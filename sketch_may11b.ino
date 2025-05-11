#include <Servo.h>

// servo
Servo servo_start;
Servo servo_tower;
const int start_pin = 10;
const int tower_pin = 3;

// tt motor
const int in3 = 7;
const int in4 = 8;
const int enB = 9;

// distnace sensor
const int st_trig = 2;
const int st_echo = 4;

const int fn_echo = 12;
const int fn_trig = 13;

float dist;
bool has_started = false;

void setup() {
  // serial/output initialization
  Serial.begin(9600);

  // servo
  servo_start.attach(start_pin);
  servo_tower.attach(tower_pin);
  servo_start.write(0);
  servo_tower.write(90);

  // ultrasonic
  pinMode(st_trig, OUTPUT);
  pinMode(st_echo, INPUT);
  pinMode(fn_trig, OUTPUT);
  pinMode(fn_echo, INPUT);

  // tt motor
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void loop() {

  analogWrite(enB, 255); // motor start

  // check if detected
  for (int i = 1; i <= 20; i++){

    dist = has_started ? calc_dist(fn_trig, fn_echo) : calc_dist(st_trig, st_echo);
    String who = has_started ? "Final: " : "Start: ";
    Serial.print(who);
    Serial.print(dist);
    Serial.println(" cm");

    // if the first sensor is active and detects the target, it activates the mechanism
    if (!has_started && dist < 10)
    {
      has_started = true;
      servo_start.write(180);
    }
    // ehse if the second sensor is active, have no blockage and detects the target it close the trap
    if (has_started && dist > 15 && dist < 20){
      servo_tower.attach(180);
    }

    delay(10);
  }

  analogWrite(enB, 0); // motor stop
  delay(200); // wait for mechanism
  
}

float calc_dist (const int trig_pin, const int echo_pin) {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);

  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  float duration = pulseIn(echo_pin, HIGH);
  return duration * 0.034 / 2; // distance in cm

}
