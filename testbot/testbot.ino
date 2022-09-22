





#define echopin A4 // echo pin
#define trigpin A5 // Trigger pin


int motor_r2 = 9;
int motor_r1 = 10;

int motor_l2 = 5;
int motor_l1 = 6;


int speed = 118;
int turn = speed=90;
int  frontdist;
long duration;

int setdist= 18;

int L_S = A0; //sensor L
int R_S = A1; //sensor R


void setup(){
 
 pinMode(motor_l1, OUTPUT);
 pinMode(motor_l2, OUTPUT);
 
 pinMode(motor_r1, OUTPUT);
 pinMode(motor_r2, OUTPUT);

 pinMode (trigpin, OUTPUT);
 pinMode (echopin, INPUT);
 
 pinMode(L_S, INPUT);
 pinMode(R_S, INPUT);

 Serial.begin(9600);
 delay(1000);
 }

void loop(){
frontdist = data();
Serial.println(frontdist); 

if(frontdist>setdist){
if ((digitalRead(L_S) == 0)&&(digitalRead(R_S) == 0)){forward();}
if ((digitalRead(L_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}
if ((digitalRead(L_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();}
if ((digitalRead(L_S) == 1)&&(digitalRead(R_S) == 1)){stop();}
}else{

turnLeft();
delay(350);
forward();
delay(1400);
turnRight();  
delay(750);
forward();
delay(800);

}

}

long data(){
 digitalWrite(trigpin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigpin,HIGH);
 delayMicroseconds(10);
 duration=pulseIn (echopin,HIGH);
 return duration / 29 / 2; 
}

void stop(){
 analogWrite(motor_l1, 0);
 analogWrite(motor_l2, 0);
 analogWrite(motor_r1, 0);
 analogWrite(motor_r2, 0);  
}

void forward(){
 analogWrite(motor_l1, speed);
 analogWrite(motor_l2, 0);
 analogWrite(motor_r1, 0);
 analogWrite(motor_r2, speed);  
}

void backward(){
 analogWrite(motor_l1, 0);
 analogWrite(motor_l2, speed);
 analogWrite(motor_r1, speed);
 analogWrite(motor_r2, 0);   
}


void turnRight(){
analogWrite(motor_l1, 0);
analogWrite(motor_l2, turn);
analogWrite(motor_r1, 0);
analogWrite(motor_r2, turn);  
}

void turnLeft(){
analogWrite(motor_l1, turn);
analogWrite(motor_l2, 0);
analogWrite(motor_r1, turn);
analogWrite(motor_r2, 0);   
}
