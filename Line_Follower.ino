const int MR_CONTROL_PIN_A = A0;
const int MR_CONTROL_PIN_B = A1;
#define motorSpeed 100
const int ML_CONTROL_PIN_A = A3;
const int ML_CONTROL_PIN_B = A2;
int IR_L;
int IR_R;
#define White 0
#define Black 1
// const int redPin = 9;
// const int greenPin = 10;
// const int bluePin = 11;

void forward() 
{
      digitalWrite(MR_CONTROL_PIN_A, HIGH);
      digitalWrite(MR_CONTROL_PIN_B, LOW);
      digitalWrite(ML_CONTROL_PIN_A, HIGH);
      digitalWrite(ML_CONTROL_PIN_B, LOW);
}

void turn_R()
{
      digitalWrite(MR_CONTROL_PIN_A, LOW);
      digitalWrite(MR_CONTROL_PIN_B, LOW);
      digitalWrite(ML_CONTROL_PIN_A, HIGH);
      digitalWrite(ML_CONTROL_PIN_B, LOW);
}

void turn_L()
{
      digitalWrite(MR_CONTROL_PIN_A, HIGH);
      digitalWrite(MR_CONTROL_PIN_B, LOW);
      digitalWrite(ML_CONTROL_PIN_A, LOW);
      digitalWrite(ML_CONTROL_PIN_B, LOW);
}

void stop() 
{
      digitalWrite(MR_CONTROL_PIN_A, LOW);
      digitalWrite(MR_CONTROL_PIN_B, LOW);
      digitalWrite(ML_CONTROL_PIN_A, LOW);
      digitalWrite(ML_CONTROL_PIN_B, LOW);
}

void setup() 
{
  pinMode(MR_CONTROL_PIN_A, OUTPUT);
  pinMode(MR_CONTROL_PIN_B, OUTPUT);
  //pinMode(MR_PWM_PIN, OUTPUT);
  //pinMode(ML_PWM_PIN, OUTPUT);
  pinMode(ML_CONTROL_PIN_A, OUTPUT);
  pinMode(ML_CONTROL_PIN_B, OUTPUT);
  digitalWrite(MR_CONTROL_PIN_A, HIGH);
  digitalWrite(MR_CONTROL_PIN_B, LOW);
  digitalWrite(ML_CONTROL_PIN_A, HIGH);
  digitalWrite(ML_CONTROL_PIN_B, LOW);
  //  pinMode(redPin, OUTPUT);
  // pinMode(greenPin, OUTPUT);
  // pinMode(bluePin, OUTPUT);
}

void loop() 
{
    IR_L = digitalRead(9);
    IR_R = digitalRead(8);
    while(IR_L == 0 && IR_R == 0)
    {
      forward();
      break;
    }

    while(IR_L == 1 && IR_R == 0)
    {
        turn_L();
        break;
    }

    while(IR_L == 0 && IR_R == 1)
    {
        turn_R();
        break;
    }

    while(IR_L == 1 && IR_R == 1)
    {
      // blinkColors();
      stop();
    }
}

// void blinkColors() {
//   for (int i = 0; i < 10; i++) { // Blink 10 times
//     // Glow Cyan color
//     setColor(0, 255, 255);
//     delay(500);
    
//     // Turn off the LED
//     setColor(0, 0, 0);
//     delay(500);
    
//     // Glow Magenta color
//     setColor(255, 0, 255);
//     delay(500);
    
//     // Turn off the LED
//     setColor(0, 0, 0);
//     delay(500);
    
//     // Glow Indigo color
//     setColor(75, 0, 130);
//     delay(500);
    
//     // Turn off the LED
//     setColor(0, 0, 0);
//     delay(500);
//   }
// }

// void setColor(int red, int green, int blue) {
//   analogWrite(redPin, red);
//   analogWrite(greenPin, green);
//   analogWrite(bluePin, blue);
// }