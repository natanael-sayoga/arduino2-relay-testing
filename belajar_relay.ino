//put COMMON on 3.3V Pin
//NO and NC on positive leg of your Electric Component and then the negative leg to ground
//and then set initial state for the relay Input Pin, 
//    if Active Low then set your initial pin state to HIGH
//    if Active High then set your initial pin state to LOW
//       **Active State -> kapan gerbang NO akan ditutup
unsigned long loopTimer = millis();
unsigned long loopInterval = 200;

boolean buttonState = true;
int button = D2;
int led = D1;
int relay = D3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(relay, OUTPUT);
  //pinMode(led, OUTPUT);

  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(relay, HIGH); //my relay is ACTIVE LOW, meaning the NORMALY OPEN gate
                             //is closed when the digitalRead is LOW
                             //hal ini berlawanan dengan expected behaviour
                             //di mana NORMALY CLOSED gate lah yang akan tertutup terlebih dahulu!
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentLoopTimer = millis();
  if(currentLoopTimer - loopTimer >= loopInterval){
    loopTimer = currentLoopTimer;
    boolean currentButtonState = digitalRead(button);
    if(currentButtonState != buttonState){
      //because we are using INPUT_PULLUP, meaning the button by default will be considered ON
      //so the idea is that when the button is pressed it will be grounded and the digitalRead 
      //will be read as OFF
      buttonState = currentButtonState;
      if(!buttonState){
        Serial.println("button pressed!");
        toggleRelay();
        checkRelayState();
      }
    }
  }
}

void checkRelayState(){
  boolean state = digitalRead(relay);
  String status = state?"THE RELAY IS ON!":"THE RELAY IS OFF";
  Serial.println(status);
}

void toggleRelay(){
  boolean state = digitalRead(relay);
  digitalWrite(relay, !state);
}
