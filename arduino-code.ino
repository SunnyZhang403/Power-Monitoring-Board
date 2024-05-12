const int current1 = A0;
const int current2 = A1;
const int current3 = A2;
const int current4 = A3;
const int current5 = A4;
const int current6 = A5;
const int current7 = A6;
const int current8 = A7;
const int voltage = A8;

double vref1;
double vref2;
double vref3;
double vref4;
double vref5;
double vref6;
double vref7;
double vref8;

double v1;
double v2;
double v3;
double v4;
double v5;
double v6;
double v7;
double v8;

double c1;
double c2;
double c3;
double c4;
double c5;
double c6;
double c7;
double c8;
int freq = 100;

void setup() {
  Serial.begin(9600);
  pinMode(current1, INPUT);
  pinMode(current2, INPUT);
  pinMode(current3, INPUT);
  pinMode(current4, INPUT);
  pinMode(current5, INPUT);
  pinMode(current6, INPUT);
  pinMode(current7, INPUT);
  pinMode(current8, INPUT);
  pinMode(voltage, INPUT);

  // calculate reference voltages
  vref1 = avgVal(current1, 50, 5);
  vref2 = avgVal(current2, 50, 5);
  vref3 = avgVal(current3, 50, 5);
  vref4 = avgVal(current4, 50, 5);
  vref5 = avgVal(current5, 50, 5);
  vref6 = avgVal(current6, 50, 5);
  vref7 = avgVal(current7, 50, 5);
  vref8 = avgVal(current8, 50, 5);

}
double avgVal(int pin, int filterLen, int delayms)
{
  int value = 0;
  double v; 

  for(int i=0; i < filterLen; i++)
  {
    value += analogRead(pin);
    delay(delayms);
  }
  v= value/filterLen;
  return v;
}


void loop() {

  v1 = avgVal(current1, 50, 1);
  v2 = avgVal(current2, 50, 1);
  v3 = avgVal(current3, 50, 1);
  v4 = avgVal(current4, 50, 1);
  v5 = avgVal(current5, 50, 1);
  v6 = avgVal(current6, 50, 1);
  v7 = avgVal(current7, 50, 1);
  v8 = avgVal(current8, 50, 1);

  // calibrate current values 
  c1 = (v1 - vref1)/55;
  c2 = (v2 - vref2)/55;
  c3 = (v3 - vref3)/55;
  c4 = (v4 - vref4)/55;
  c5 = (v5 - vref5)/55;
  c6 = (v6 - vref6)/55;
  c7 = (v7 - vref7)/55;
  c8 = (v8 - vref8)/55;

  float datalist [9] = {voltage,c1,c2,c3,c4,c5,c6,c7,c8};

  // print data to serial
  for(int i = 0; i<sizeof(datalist)/sizeof(datalist[0]);i++){
    
    Serial.print(datalist[i]);
    Serial.print("x");
  };
  Serial.println();

  delay(freq);
}
