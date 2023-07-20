#include <Servo.h>

#define TRIGGER_PIN 3
#define ECHO_PIN 2
#define SERVO_PIN 9

Servo servo;

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  servo.attach(SERVO_PIN);
  servo.write(0); // Mengatur posisi awal servo (tutup)
  
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  
  // Mengirimkan sinyal ultrasonik
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Menerima waktu pantulan ultrasonik
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Menghitung jarak berdasarkan waktu pantulan
  distance = (duration / 2) / 29.1;
  
  Serial.print("Jarak: ");
  Serial.println(distance);
  
  // Mengontrol servo berdasarkan jarak
  if (distance <= 30) {
    // Jarak kurang dari atau sama dengan 10 cm, buka tutup sampah
    servo.write(150); // Mengatur posisi servo (buka)
    delay(3000); // Tunggu selama 2 detik
    
    // Kosongkan sampah (tambahkan logika sesuai kebutuhan)
    
    servo.write(0); // Mengatur posisi servo (tutup)
    delay(2000); // Tunggu selama 2 detik
  }
  
  delay(10 ); // Tunda 0,5 detik sebelum pengukuran selanjutnya
}