// File:          my_controller.cpp
// Date : 12/10/2022
// Description: Prova simulazione del robot P-ROB3
// Author: Luizaga Raul
// Modifications:

#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include<webots/PositionSensor.hpp>
#include <unistd.h>
#define TIME_STEP 64 // tempo di clok 
#define MAX_SPEED 1.74 // velocità massima per tutti i motori 
#define MAX_SPEED1 1 // velocità massima pinze  1.0472

using namespace webots;


const double PI = 3.1415926535897932384626433832795028841971693993751058209;
int main(int argc, char **argv) {
  // create the Robot instance.
  Robot *robot = new Robot();
  
  /* 
    Dentro HingeJoint troviamo nodo devide che ha al suo interno motore e sensore 
    di posizione.
    
    Nel codice dovrò chiamarli in questo modo:
    
    RotatioinalMotor "motor n"
    PositionSensor "motor n sensor"
    
    I children(alcuni contenuti dentro "ednPoint Solid") hanno al loro interno HingeJoint
  */
  
  //  CREO INSTANZE DEI MOTORI DEL ROBOT
  
  // Nome  di P-RobB3  "P-Rob3"
  Motor* motore_1 = new Motor("motor 1"); // tutto il robot viene selezionato
  // Nome children "link_1_2 , dentro endPoint"
  Motor* motore_2 = new Motor("motor 2");
  // nome children "link_2_3 , dentro endPoint"
  Motor* motore_3 = new Motor("motor 3");
  // nome children "link_3_4 , dentro endPoint"
  Motor* motore_4 = new Motor("motor 4");
  // nome children "link_4_5 , dentro endPoint"
  Motor* motore_5 = new Motor("motor 5");
  // nome children "link_5_6 , dentro endPoint"
  Motor* motore_6 = new Motor("motor 6");
  
    /*in questo ultimo children "link_6_top"
   abbiamo 8 TouchSensor con id "button i", i = 0,...,7
  
  Oltre a questo ha un nodo Group che contiene un children "link_base_tcp180"
  dentro il quase sono presenti "DEF RIGHT_FINGER HingeJoint"(che contiene 
  device -> motore e sensore posizione 7) e "DEF RIGHT_FINGER HingeJoint"(che 
  contiene device -> motore e sensori posizione 8).
  c'è anche un sensore alla base  chiamato delle pinze chiamato "gripper middle distance
  sensor"
  MOTORI DELLE PINZE
  */
  Motor* motore_pdx = new Motor("motor 7");
  Motor* motore_psx = new Motor("motor 7 left");
  
  /*
  Dentro l'oggetto pinza sinistra è presente un altro children  chiamato "left finger"
  con dentro dei sensori di distanza "left finger sensor i", i = 0,...,3;
  */
  
  // SENSORI DI POSIZIONE ASSOCIATI AI MOTORI 
   PositionSensor* pos_1 = new PositionSensor("motor 1 sensor");
   pos_1->enable(TIME_STEP);
   
   PositionSensor* pos_2 = new PositionSensor("motor 2 sensor");
   pos_2->enable(TIME_STEP);
   
   PositionSensor* pos_3 = new PositionSensor("motor 3 sensor");
   pos_3->enable(TIME_STEP);
   
   PositionSensor* pos_4 = new PositionSensor("motor 4 sensor");
   pos_4->enable(TIME_STEP);
   
   PositionSensor* pos_5 = new PositionSensor("motor 5 sensor");
   pos_5->enable(TIME_STEP);
   
   PositionSensor* pos_6 = new PositionSensor("motor 6 sensor");
   pos_6->enable(TIME_STEP);
   
   PositionSensor* pos_pdx = new PositionSensor("motor 7 sensor");
   pos_pdx->enable(TIME_STEP);
   
   PositionSensor* pos_psx = new PositionSensor("motor 7 left sensor");
   pos_psx->enable(TIME_STEP);
  
  // SETTAGGIO DELLE POSIZIONI E VELOCITA INIZIALI DEI MOTORI DEL P-ROB3
  
  motore_1->setPosition(INFINITY); // abilitazione movimento rotatorio infinito
  motore_1->setVelocity(0.0);
  
  motore_2->setPosition(INFINITY);
  motore_2->setVelocity(0.0);
  
  motore_3->setPosition(INFINITY);
  motore_3->setVelocity(0.0);
  
  motore_4->setPosition(INFINITY);
  motore_4->setVelocity(0.0);  
  
  motore_5->setPosition(INFINITY);
  motore_5->setVelocity(0.0);  
  
  motore_6->setPosition(INFINITY);
  motore_6->setVelocity(0.0);  
  
  motore_pdx->setPosition(INFINITY);
  motore_pdx->setVelocity(0.0);
  
  motore_psx->setPosition(INFINITY);
  motore_psx->setVelocity(0.0);
  
 // SETTO LE VELOCITA' MASSIME PER OGNI MOTORE PRESENTE NEL PROB3
  double motore_1_vmax = MAX_SPEED;
  double motore_2_vmax = MAX_SPEED;
  double motore_3_vmax = MAX_SPEED;
  double motore_4_vmax = MAX_SPEED;
  double motore_5_vmax = MAX_SPEED;
  double motore_6_vmax = MAX_SPEED;
  double motore_pdx_vmax = MAX_SPEED1;     
  double motore_psx_vmax = MAX_SPEED1;     
  
 // INSERISCO IN GRADI LE POSIZIONE TENENDO CONTO DEI LIMITI 
 
  double pos_1_goal = 100 * (PI/180); // massimo 170 gradi
  std::cout<<"posizione desiderata : "<< pos_1_goal<<std::endl;
  double pos_2_goal = 10 * (PI/180); // massimo 109.5 gradi
  double pos_3_goal = 60 * (PI/180); // massimo 114.5 gradi 
  double pos_4_goal = 90 * (PI/180); // massimo 170 gradi
  double pos_5_goal = 60 * (PI/180); // massimo 114.5 gradi
  double pos_6_goal = 90 * (PI/180); // massimo 169.5 gradi
  double pos_pdx_goal = 60 * (PI/180); // massimo 60 gradi
  double pos_psx_goal = 60 * (PI/180); // massimo 60 gradi
 
  bool controllo_1 = false;
  bool controllo_2 = false;
  bool controllo_3 = false;
  bool controllo_4 = false;
  bool controllo_5 = false;
  bool controllo_6 = false;
  bool controllo_pdx = false;
  bool controllo_psx = false; 
  
  robot->step(TIME_STEP); // utilizzato per la sincronizzazione di sensori ed attuatori...
 
  while (robot->step(TIME_STEP) != -1) {
  
   // Set position credo dia coordinate assolute e non relative, il discorso vale anche per valori negativi
    if(controllo_1 == false){
      motore_1->setVelocity(motore_1_vmax);
      motore_1->setPosition(pos_1_goal); // motore 1 può spostarsi a massimo 2.95903 (170 gradi) (rotazione intorno a se stesso )
      std::cout<<"posizione del motore 1 gradi : "<< pos_1->getValue()*(180/PI)<<std::endl;
      std::cout<<"posizione del motore 1 radianti  : "<< pos_1->getValue()<<std::endl;

      if( ( abs(pos_1->getValue() - pos_1_goal )< 0.01)){
        sleep(1);
        controllo_1 = true;

        }
    }

    
 
    if(controllo_1 == true && controllo_2 == false){
      motore_2->setVelocity(motore_2_vmax);
      motore_2->setPosition(pos_2_goal); // massimo spostamento 1.91148(109.5 gradi) altrimenti colpisce il pavimento
      std::cout<<"posizione del motore 2 : "<< pos_2->getValue()*(180/PI)<<std::endl;
      std::cout<<"posizione del motore 2 radianti  : "<< pos_2->getValue()<<std::endl;

      if( ( abs(pos_2->getValue() - pos_2_goal )< 0.01)){
        sleep(1);
        controllo_2 = true;

        }
      
    
    }


    
    
    if(controllo_2 == true && controllo_3 == false){
    
      motore_3->setVelocity(motore_3_vmax);
      motore_3->setPosition(pos_3_goal); // massimo spostamento possibile 1.99927(114.5 gradi) altrimenti colpisce il pavimento 
      std::cout<<"posizione del motore 3 : "<< pos_3->getValue()*(180/PI)<<std::endl;
      std::cout<<"posizione del motore 3 radianti  : "<< pos_3->getValue()<<std::endl;
           
      if( ( abs(pos_3->getValue() - pos_3_goal )< 0.01)){
        sleep(1);
        controllo_3 = true;

        }
      }
    


 
    if(controllo_3 == true && controllo_4 == false){

      motore_4->setVelocity(motore_4_vmax);
      motore_4->setPosition(pos_4_goal); // massimo spostamento possibile 2.95153(170 gradi) (rotazione intorno a se stesso)
      std::cout<<"posizione del motore 4 : "<< pos_4->getValue()*(180/PI)<<std::endl;  

      if( ( abs(pos_4->getValue() - pos_4_goal )< 0.01)){
        sleep(1);
        controllo_4 = true;
        }
      }

  
 

 
    if(controllo_4 == true && controllo_5 ==false){
      motore_5->setVelocity(motore_5_vmax);
      motore_5->setPosition(pos_5_goal);  // massimo spostamento possibile 1.9977(114.5 gradi), si piega
      std::cout<<"posizione del motore 5 : "<< pos_5->getValue()*(180/PI)<<std::endl;

      if( ( abs(pos_5->getValue() - pos_5_goal )< 0.01)){
        sleep(1);
        controllo_5 = true;
      }


    }

 

    if(controllo_5 == true && controllo_6 == false ){
      motore_6->setVelocity(motore_6_vmax); // rotazione base delle pineza 
      motore_6->setPosition(pos_6_goal);  // massimo spostamento possibile 2.95833 (169.5 gradi)
      std::cout<<"posizione del motore 6 : "<< pos_6->getValue()*(180/PI)<<std::endl;

      if( ( abs(pos_6->getValue() - pos_6_goal )< 0.01)){
        sleep(1);
        controllo_6 = true;
        }
    }
 

    if(controllo_6 == true && controllo_pdx == false && controllo_psx == false){
   
      motore_pdx->setVelocity(motore_pdx_vmax-0.8);  // dalla simulazione sembra la sinistra perchè ruotato
      motore_pdx->setPosition(pos_pdx_goal);  // posizione massima 1.0472(60 gradi), (la pinza sinistra )
      std::cout<<"posizione del motore pdx : "<< pos_pdx->getValue()*(180/PI)<<std::endl;
      if( ( abs(pos_pdx->getValue() - pos_pdx_goal )< 0.01)){
        sleep(1);
        controllo_pdx = true;
        }
    
    }


 

    if(controllo_pdx == true && controllo_psx == false){
      motore_psx->setVelocity(motore_psx_vmax-0.8); //dalla simulazione sembra pinza destra perchè ruotato
      motore_psx->setPosition(pos_psx_goal);  // posizione massima 1.0472,(60 gradi) (pinza destra)
      std::cout<<"posizione del motore psx : "<< pos_psx->getValue()*(180/PI)<<std::endl;

      if( ( abs(pos_psx->getValue() - pos_psx_goal )< 0.01)){
        sleep(1);
        controllo_psx = true;
        }

    }

    std::cout<<"sono ancora dentro il ciclo while !"<<std::endl;
  };
  
  
  delete robot;
  return 0;
}
