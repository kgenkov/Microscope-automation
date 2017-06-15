/* 
 Microscope-automation
 Copyright© 2017 Maya Zhekova; Anton Zyapkov; Kaloyan Genkov <kgenkov@uni-sofia.bg>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

int _joysteps = 8;
void setup() {
Serial.begin(9600);
Serial.setTimeout (100);
  pinMode(7, OUTPUT);      // sets the digital pin as output
  pinMode(8, OUTPUT);      // sets the digital pin as output
  pinMode(9, OUTPUT);      // sets the digital pin as output
  pinMode(10, OUTPUT);      // sets the digital pin as output
  pinMode(11, OUTPUT);      // sets the digital pin as output
  pinMode(12, OUTPUT);      // sets the digital pin as output
  pinMode(13, OUTPUT);      // sets the digital pin as output

 PORTB=B000000;
 PORTD=B10000000;//disable movement
}
int Enable_movement()
{PORTD=PORTD&B01111111;
return 0;
  }
int Disable_movement()
{PORTD=PORTD|B10000000;
return 0;
  }
int ChooseMotor(int choice, int dir, int steps, int MovSpeed=1000)
{
  
 if (choice==1)TurnOnMotorX(dir, steps,MovSpeed);
 if (choice==2)TurnOnMotorY(dir, steps,MovSpeed);
 if (choice==3)TurnOnMotorZ(dir, steps,MovSpeed); 
 
  }
int TurnOnMotorX(int dir, int steps,int MovSpeed)
{
  int i;
  if (dir==1) PORTB=PORTB | B010000;
  if (dir==2) PORTB=PORTB | B000000;
  Enable_movement();
  for (i=1;i<=2*steps;i++)
  {
    PORTB=PORTB ^ B100000;
    delayMicroseconds(MovSpeed);
 
  }
 PORTB=B000000;
 Disable_movement();  
 return 1; 
}
int TurnOnMotorY(int dir, int steps,int MovSpeed)
{
  int i;
  if (dir==1) PORTB=PORTB | B000100;
  if (dir==2) PORTB=PORTB | B000000;
    Enable_movement();
  for (i=1;i<=2*steps;i++)
  {
    PORTB=PORTB ^ B001000;
    delayMicroseconds(MovSpeed);
  }
 PORTB=B000000; 
 Disable_movement();  
 return 1; 
}
int TurnOnMotorZ(int dir, int steps,int MovSpeed)
{
  int i;
  if (dir==1) PORTB=PORTB | B000001;
  if (dir==2) PORTB=PORTB | B000000;
    Enable_movement();
  for (i=1;i<=2*steps;i++)
  {
    PORTB=PORTB ^ B000010;
    delayMicroseconds(MovSpeed);
  }
 PORTB=B000000;
 Disable_movement();  
 return 1; 
}
   
void loop() {PORTD=B10000000;
  // put your main code here, to run repeatedly:
  int choice=0,isready=0,dir,steps,choose_movement=1,joyx=512,joyy=512,joyp=0;
joyx=analogRead(0);
joyy=analogRead(1);
joyp=analogRead(2);
Serial.print(joyy);
if (joyx>600 ||joyx<400 ||joyy>600|| joyy<400) isready=4;

if(isready==0) {Serial.write("Motor X/Y/Z 1/2/3: \n");
do{choice= Serial.readStringUntil('\n').toInt();isready=1;}while(choice==0 && (analogRead(0)<600&&analogRead(0)>400)&&(analogRead(1)<600&&analogRead(1)>400));  
if (choice==0)isready=4;}
if(isready==1) {Serial.write("Direction 1/2: \n");    do{dir= Serial.readStringUntil('\n').toInt();isready=2;}while(dir<=0||dir>2);   }
if(isready==2) {Serial.write("Steps /ne prekalqvai/: o]\n");do{steps= Serial.readStringUntil('\n').toInt();isready=3;}while(steps==0);   }


if(isready==3) {
Serial.print(choice); Serial.print(dir); Serial.print(steps); isready=0;
ChooseMotor(choice,dir,steps);
}
if(isready=4) {
  int joyvaluex = (joyx-512)/15;
  int joyvaluey = (joyy-512)/15;
  int dirx = 2;
  int diry = 2;
  if (joyvaluex < 0) {dir=1; joyvaluex = -joyvaluex;}
  if (joyvaluey < 0) {dir=1; joyvaluey = -joyvaluey;}
  int joyspeedx = 256*(35-joyvaluex);
  int joyspeedy = 256*(35-joyvaluey);
  int joyspeed = min (joyspeedx, joyspeedy);
  if (joyx>600 ) {dir=2;choice=1;/*Serial.print(choice); Serial.print(dir); Serial.print(steps);*/ChooseMotor(choice,dir,_joysteps,joyspeedx);isready=0;}
  if (joyx<400 ) {dir=1;choice=1;/*Serial.print(choice); Serial.print(dir); Serial.print(steps);*/ChooseMotor(choice,dir,_joysteps,joyspeedx); isready=0;}

  if (joyy>600 ) {dir=2;choice=2;/*Serial.print(choice); Serial.print(dir); Serial.print(steps);*/ChooseMotor(choice,dir,_joysteps,joyspeedy); isready=0;}
  if (joyy<400 ) {dir=1;choice=2;/*Serial.print(choice); Serial.print(dir); Serial.print(steps);*/ChooseMotor(choice,dir,_joysteps,joyspeedy); isready=0;} 
}
} 
