int sensor1 = A0;
int sensor2 = A1;
float data1;
float data2;
int freq = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);
  pinMode(sensor7, INPUT);
  pinMode(sensor8, INPUT);

}

void loop() {



  // put your main code here, to run repeatedly:
  data1 = analogRead(sensor1);
  data2 = analogRead(sensor2);
  data3 = analogRead(sensor3);
  data4 = analogRead(sensor4);
  data5 = analogRead(sensor5);
  data6 = analogRead(sensor6);
  data7 = analogRead(sensor7);
  data8 = analogRead(sensor8);
  float datalist [8] = {data1, data2, data3, data4, data5, data6, data7, data8, data9};
  // Serial.print(data);
  for(int i = 0; i<sizeof(datalist)/sizeof(datalist[0]);i++){
    
    Serial.print(datalist[i]);
    Serial.print("x");
  };
  Serial.println();

  delay(freq);
}
