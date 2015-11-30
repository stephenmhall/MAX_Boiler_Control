void Boiler_ON() {
  digitalWrite(LEDPIN, HIGH);
  digitalWrite(BOILERLED, HIGH);
  Serial.println("Boiler ON");
  for (int x = 0; x <= 3; x++) {
    RF_tx(170);           // Output the common part of the packet 6 bytes 170 169 209 75 82 213 53 77 82
    RF_tx(169);           // 85 84 232 165 169 106 154 166 169
    RF_tx(213);
    RF_tx(75);
    RF_tx(82);
    RF_tx(213);
    RF_tx(53);          // Turn the boiler on
    RF_tx(77);
    RF_tx(82);
    RF_tx(255);
    digitalWrite(LEDPIN, LOW);
    //delay(1000);
  }
}

void Boiler_OFF() {
  digitalWrite(LEDPIN, HIGH);
  digitalWrite(BOILERLED, LOW);
  Serial.println("Boiler OFF");
  for (int x = 0; x <= 3; x++) {
    RF_tx(170);           // Output the common part of the packet 6 bytes 170 169 213 75 82 213 53 77 82
    RF_tx(169);
    RF_tx(213);
    RF_tx(75);
    RF_tx(82);
    RF_tx(213);
    RF_tx(85);
    RF_tx(85);
    RF_tx(82);
    RF_tx(255);
    digitalWrite(LEDPIN, LOW);
    //delay(1000);
  }
}

void RF_tx(uint8_t b) { // this function writes the serial MSB first
    
  int bitDelay = _bitPeriod - clockCyclesToMicroseconds(50); // a digitalWrite is about 50 cycles
  byte mask;

//  digitalWrite(TRANSMIT_PIN, LOW);   // send a start bit
//  delayMicroseconds(bitDelay);

  for (mask = B10000000; mask; mask >>= 1) {  // start with bit 7 and right shift the mask until mask = 1
    if (b & mask){ // choose bit
      digitalWrite(TRANSMIT_PIN,LOW); // send 1
    }
    else{
      digitalWrite(TRANSMIT_PIN,HIGH); // send 0
    }
    delayMicroseconds(bitDelay);
  }

//  digitalWrite(TRANSMIT_PIN, HIGH);    // send a stop bit
//  delayMicroseconds(bitDelay);
}
