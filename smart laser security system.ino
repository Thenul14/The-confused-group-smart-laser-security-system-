#define LDR_PIN A0      // LDR connected to Analog 
#define GREEN_LED 6     // Green LED pin
#define RED_LED 7       // Red LED pin
#define BUZZER 8        // Buzzer pin
#define pushbutton 9    // Push button pin

int threshold = 200; // Adjust based on environment lighting
bool alarmtrigger = false;

void setup() {
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
  	pinMode(pushbutton, INPUT_PULLUP);
    Serial.begin(9600); // For debugging
}

void loop() {
    int ldrValue = analogRead(LDR_PIN);
    Serial.println(ldrValue); // Print LDR value to Serial Monitor
  
  	if (!alarmtrigger && ldrValue <= threshold) {
      alarmtrigger = true;
      
    }

    if (alarmtrigger) { // Laser detected
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED, HIGH);
      	tone(BUZZER,1000);
        
    } else { // Laser blocked or turned off
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED, LOW);
      	noTone(BUZZER);
        
    }
  
  	if (digitalRead(pushbutton) == HIGH ) {
      alarmtrigger = false;
      
    }

    delay(100); // Small delay for stability
} 