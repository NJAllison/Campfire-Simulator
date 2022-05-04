/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nelson.allison@aberdeencarshops.ca> wrote this file.  As long as you retain
 * this notice you can do whatever you want with this stuff. If we meet some day
 * , and you think this stuff is worth it, you can buy me a beer in return.
 * Nelson Allison
 * -----------------------------------------------------------------------------
 * Campfire with 4 Leds Red, Orange, Yellow, White
*/
int tim_delay = 40;   //this is the loop time in milliseconds
// how often leds can change
#define numleds  4              // total number of LEDs for the simulation
byte ledpins [] = {6,9,10,11}; // the pins in order that will drive each LED (Yellow,Red,White,Orange)
byte time_on [] = {60,50,50,10}; //the percentage of time on for each color from 1-100

void setup() {
  randomSeed(analogRead(0));
  // initialize the digital pins as an outputs
  for (int i = 0; i < numleds; i++) {
    pinMode(ledpins[i], OUTPUT);    // make all pins outputs
    analogWrite(ledpins[i], 0);  // turn all off to start
  }
}
void loop() {
  int i;
  i = random (0, numleds + 1);
  analogWrite(ledpins [i], lightsw(time_on[i]) );
  delay(tim_delay);              // wait for a bit--this is the master loop delay
}
int lightsw(int time_percent_ON) {
  if (random(0, 100) > time_percent_ON) return 0; // a low time_percent_ON means the LED is on less
  else return random(10,100);
}
