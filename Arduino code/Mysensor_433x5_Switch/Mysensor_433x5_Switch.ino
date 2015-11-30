// Example sketch för a "light switch" where you can control light or something 
// else from both vera and a local physical button (connected between digital
// pin 3 and GND).
// This node also works as a repeader for other nodes

#include <MySensor.h>
#include <SPI.h>
#include <RCSwitch.h>

#define NODE_ID 20
#define SKETCH_NAME "433_Switch"
#define SKETCH_VERSION "1.0"
#define NODE_REPEAT true

#define CHILD_ID_SW1 0   // Id of the sensor child
#define CHILD_ID_SW2 1   // Id of the sensor child
#define CHILD_ID_SW3 2   // Id of the sensor child
#define CHILD_ID_SW4 3   // Id of the sensor child
#define CHILD_ID_SW5 4   // Id of the sensor child
#define CHILD_ID_BOILER 5   // Id of the sensor child

#define TRANSMIT_PIN  7  // Arduino Digital I/O pin number for relay
#define LEDPIN 5          // RF Transmit LED
#define BOILERLED 6       // Boiler ON LED
#define DEBOUNCE 10  // how many ms to debounce, 5+ ms is usually plenty

//define the buttons that we'll use.
//byte buttons[] = {2, 3, 4, 5, 6, 7};

//determine how big the array up above is, by checking the size
//#define NUMBUTTONS sizeof(buttons)

//track if a button is just pressed, just released, or 'currently pressed' 
//byte pressed[NUMBUTTONS], justpressed[NUMBUTTONS], justreleased[NUMBUTTONS];
//byte previous_keystate[NUMBUTTONS], current_keystate[NUMBUTTONS];

#define SW_ON 1
#define SW_OFF 0

int oldValueSW1=0;
int oldValueSW2=0;
int oldValueSW3=0;
int oldValueSW4=0;
int oldValueSW5=0;
int oldValueBOILER=0;
bool state;
int _bitPeriod = 1000000 / 2000;   // define the serial baudrate in microseconds

MySensor gw;
MyMessage msgSw1(CHILD_ID_SW1,V_LIGHT);
MyMessage msgSw2(CHILD_ID_SW2,V_LIGHT);
MyMessage msgSw3(CHILD_ID_SW3,V_LIGHT);
MyMessage msgSw4(CHILD_ID_SW4,V_LIGHT);
MyMessage msgSw5(CHILD_ID_SW5,V_LIGHT);
MyMessage msgSw6(CHILD_ID_BOILER,V_LIGHT);

RCSwitch mySwitch = RCSwitch(); // initiate RC Switch


void setup()  
{   
  
  
  gw.begin(incomingMessage, NODE_ID, NODE_REPEAT);

  // Send the sketch version information to the gateway and Controller
  gw.sendSketchInfo(SKETCH_NAME, SKETCH_VERSION);
  
  // Setup 433 Transmitter
  mySwitch.enableTransmit(TRANSMIT_PIN);
  mySwitch.setPulseLength(200);   // Optional set pulse length.320
  
  // Register all sensors to gw (they will be created as child devices)
  gw.present(CHILD_ID_SW1, S_LIGHT);
  gw.present(CHILD_ID_SW2, S_LIGHT);
  gw.present(CHILD_ID_SW3, S_LIGHT);
  gw.present(CHILD_ID_SW4, S_LIGHT);
  gw.present(CHILD_ID_SW5, S_LIGHT);
  gw.present(CHILD_ID_BOILER, S_LIGHT);
  
  //byte i;
  
  // Make input &amp; enable pull-up resistors on switch pins
  //for (i=0; i< NUMBUTTONS; i++) {
   // pinMode(buttons[i], INPUT);
   // digitalWrite(buttons[i], HIGH);
  //}

}


/*
*  Example on how to asynchronously check for new messages from gw
*/
void loop() 
{
  gw.process();
  
//  byte thisSwitch=thisSwitch_justPressed();
//  switch(thisSwitch)
//  {  
//  case 0: 
//    Serial.println("switch 1 just pressed");
//    gw.send(msgSw1.set(state?false:true), true); // Send new state and request ack back
//    break;
//  case 1: 
//    Serial.println("switch 2 just pressed");
//    gw.send(msgSw2.set(state?false:true), true); // Send new state and request ack back
//    break;
//  case 2: 
//    Serial.println("switch 3 just pressed");
//    gw.send(msgSw3.set(state?false:true), true); // Send new state and request ack back
//    break;
//  case 3: 
//    Serial.println("switch 4 just pressed");
//    gw.send(msgSw4.set(state?false:true), true); // Send new state and request ack back
//    break;
//  case 4: 
//    Serial.println("switch 5 just pressed");
//    gw.send(msgSw5.set(state?false:true), true); // Send new state and request ack back
//    break;
//  case 5: 
//    Serial.println("switch 6 just pressed");
//    gw.send(msgSw6.set(state?false:true), true); // Send new state and request ack back
//    break;  
//  }
}

//void check_switches()
//{
//  static byte previousstate[NUMBUTTONS];
//  static byte currentstate[NUMBUTTONS];
//  static long lasttime;
//  byte index;
//  if (millis() < lasttime) {
//    // we wrapped around, lets just try again
//    lasttime = millis();
//  }
//  if ((lasttime + DEBOUNCE) > millis()) {
//    // not enough time has passed to debounce
//    return; 
//  }
//  // ok we have waited DEBOUNCE milliseconds, lets reset the timer
//  lasttime = millis();
//  for (index = 0; index < NUMBUTTONS; index++) {
//    justpressed[index] = 0;       //when we start, we clear out the "just" indicators
//    justreleased[index] = 0;
//    currentstate[index] = digitalRead(buttons[index]);   //read the button
//    if (currentstate[index] == previousstate[index]) {
//      if ((pressed[index] == LOW) && (currentstate[index] == LOW)) {
//        // just pressed
//        justpressed[index] = 1;
//      }
//      else if ((pressed[index] == HIGH) && (currentstate[index] == HIGH)) {
//        justreleased[index] = 1; // just released
//      }
//      pressed[index] = !currentstate[index];  //remember, digital HIGH means NOT pressed
//    }
//    previousstate[index] = currentstate[index]; //keep a running tally of the buttons
//  }
//}
 
//byte thisSwitch_justPressed() {
//  byte thisSwitch = 255;
//  check_switches();  //check the switches & get the current state
//  for (byte i = 0; i < NUMBUTTONS; i++) {
//    current_keystate[i]=justpressed[i];
//    if (current_keystate[i] != previous_keystate[i]) {
//      if (current_keystate[i]) thisSwitch=i;
//    }
//    previous_keystate[i]=current_keystate[i];
//  }  
//  return thisSwitch;
//}
 
void incomingMessage(const MyMessage &message) {
  // We only expect one type of message from controller. But we better check anyway.
  if (message.isAck()) {
    Serial.println("This is an ack from gateway");
  }

  if (message.type == V_LIGHT && message.sensor != CHILD_ID_BOILER) {
    Serial.println("Flipping switch");
    RFSwitch(message.sensor, message.getBool());
   }
  if (message.type == V_LIGHT && message.sensor == CHILD_ID_BOILER) {
    Serial.println("Flipping Boiler");
    if (message.getBool()){
      Boiler_ON();
    }
    else {
      Boiler_OFF();
    }
  }
}




