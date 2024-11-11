#include <BluetoothSerial.h>
BluetoothSerial SerialBT;
// Motor pins for L298N 
int ENA = 23;  // Right motor speed (PWM)
int ENB = 22;  // Left motor speed (PWM)
int IN1 = 16;  // Right motor forward
int IN2 = 17;  // Right motor backward
int IN3 = 18;  // Left motor forward
int IN4 = 19;  // Left motor backward
int motorSpeed = 200;  // Speed (0-255)
void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Robot");  // Bluetooth name
  Serial.println("The device started, now you can pair it with Bluetooth!");
  // Motor pins setup
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
void loop() {
  if (SerialBT.available()) {
    String command = SerialBT.readString();
    command.toLowerCase();  // Convert to lowercase to handle case-insensitivity
    Serial.println("Received Command: " + command);
    if (command.indexOf("forward") != -1) {
      moveForward();
    } else if (command.indexOf("backward") != -1) {
      moveBackward();
    } else if (command.indexOf("left") != -1) {
      turnLeft();
    } else if (command.indexOf("right") != -1) {
      turnRight();
    } else if (command.indexOf("stop") != -1) {
      stopMotors();
    } else if (command.indexOf("speed") != -1) {
      int newSpeed = extractSpeed(command);
      setMotorSpeed(newSpeed);
    }
  }
}
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}
void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}
void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}
void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
// Extract speed from command
int extractSpeed(String command) {
  int index = command.indexOf("speed");
  if (index != -1) {
    String speedStr = command.substring(index + 5);  // Extract the part after "speed"
    int newSpeed = speedStr.toInt();
    return constrain(newSpeed, 0, 255);  // Ensure the speed is between 0 and 255
  }
  return motorSpeed;  // Return current speed if no speed found
}
// Set new motor speed
void setMotorSpeed(int speed) {
  motorSpeed = speed;
  Serial.println("New speed set: " + String(motorSpeed));
}