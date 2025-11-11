#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Lock"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "YOUR_WIFI_SSID";  
char pass[] = "YOUR_WIFI_PASSWORD";  

#define RELAY_PIN 5       // D1 → Relay
#define BUZZER_PIN 4      // D2 → Buzzer

bool isLocked = false;
bool securityEnabled = false;

BlynkTimer timer;

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);  // Lock initially OFF
  digitalWrite(BUZZER_PIN, LOW);

  timer.setInterval(1000L, updateStatus);  // Update status every second
}

// Handle button press (lock/unlock)
BLYNK_WRITE(V1) {
  if (param.asInt() == 1) {
    if (securityEnabled) {
      int pinCode = random(1000, 9999);  // Random PIN code
      Serial.print("Enter PIN: "); Serial.println(pinCode);

      Blynk.virtualWrite(V3, "Enter PIN: " + String(pinCode));

      // Simulate a 10-second delay for PIN entry
      delay(10000);  

      // For simplicity, assuming PIN is always correct
      digitalWrite(RELAY_PIN, HIGH);
      digitalWrite(BUZZER_PIN, HIGH);
      delay(500);   // Beep duration
      digitalWrite(BUZZER_PIN, LOW);

      isLocked = true;
    } else {
      digitalWrite(RELAY_PIN, HIGH);
      digitalWrite(BUZZER_PIN, HIGH);
      delay(500);
      digitalWrite(BUZZER_PIN, LOW);
      isLocked = true;
    }
  } else {
    digitalWrite(RELAY_PIN, LOW);
    isLocked = false;
  }
}

// Checkbox for security
BLYNK_WRITE(V2) {
  securityEnabled = param.asInt();
}

// Display lock status
void updateStatus() {
  if (isLocked) {
    Blynk.virtualWrite(V3, "Locked 🔒");
  } else {
    Blynk.virtualWrite(V3, "Unlocked 🔓");
  }
}

void loop() {
  Blynk.run();
  timer.run();
}
