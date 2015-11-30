void RFSwitch(int id, boolean state) {
  if(state) {
    switch (id) {
      case 0:
      {
        digitalWrite(LEDPIN, HIGH);
        char array[50];
        String swid, swno, swst, rfd;
        swid = "0100000101";
        swno = "0101010011";
        swst = "0011";
        rfd = String(swid) + String(swno) + String(swst);
        rfd.toCharArray(array, 50);
        mySwitch.send(array); //1 on
        Serial.println("Switch 1 ON");
        digitalWrite(LEDPIN, LOW);
        break;
      }
      case 1:
        digitalWrite(LEDPIN, HIGH);
        mySwitch.send("010000010101010111000011"); //2 on
        Serial.println("Switch 2 ON");
        digitalWrite(LEDPIN, LOW);
        break;
      case 2:
        digitalWrite(LEDPIN, HIGH);
        mySwitch.send("010000010101011100000011"); //3 on
        Serial.println("Switch 3 ON");
        digitalWrite(LEDPIN, LOW);
        break;
      case 3:
        digitalWrite(LEDPIN, HIGH);
        mySwitch.send("010000010111010100000011"); //4 on
        Serial.println("Switch 4 ON");
        digitalWrite(LEDPIN, LOW);
        break;
      case 4:
        digitalWrite(LEDPIN, HIGH);
        mySwitch.send("010000010111010100000011"); //5 on
        Serial.println("Switch 5 ON");
        digitalWrite(LEDPIN, LOW);
        break;
    }
  }else {
    switch (id) {
      case 0:
        digitalWrite(LEDPIN, HIGH);
        mySwitch.send("010000010101010100111100"); //1 off
        Serial.println("Switch 1 OFF");
        digitalWrite(LEDPIN, LOW);
        break;
      case 1:
        digitalWrite(LEDPIN, HIGH);
        mySwitch.send("010000010101010111001100"); //2 off
        Serial.println("Switch 2 OFF");
        digitalWrite(LEDPIN, LOW);
        break;
      case 2:
        digitalWrite(LEDPIN, HIGH);
        mySwitch.send("010000010101011100001100"); //3 off
        Serial.println("Switch 3 OFF");
        digitalWrite(LEDPIN, LOW);
        break;
      case 3:
        digitalWrite(LEDPIN, HIGH);
        mySwitch.send("010000010101110100001100"); //4 off
        Serial.println("Switch 4 OFF");
        digitalWrite(LEDPIN, LOW);
        break;
      case 4:
        digitalWrite(LEDPIN, HIGH);
        mySwitch.send("010000010111010100001100"); //5 off
        Serial.println("Switch 5 OFF");
        digitalWrite(LEDPIN, LOW);
        break;
    }
  }
}
