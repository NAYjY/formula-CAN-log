void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
uint8_t  A= 1234;
Serial.print(A);
Serial.print(",");
Serial.print(micros());
Serial.print(",");
Serial.print(String(A));
Serial.print(",");
Serial.println(micros());

Serial.print(A,HEX);
Serial.print(",");
Serial.print(micros());
Serial.print(",");
Serial.print(String(A,HEX));
Serial.print(",");
Serial.println(micros());

Serial.print(A,BIN);
Serial.print(",");
Serial.print(micros());
Serial.print(",");
Serial.print(String(A,BIN));
Serial.print(",");
Serial.println(micros());
}
