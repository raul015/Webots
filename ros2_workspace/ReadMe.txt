1)
Per fare il build dei package all'interno della cartella src
eseguire da terminale il comando :

colcon build
alternativa : colcon build --symlink-install

Verranno generate le cartelle build, install e log 

2) Comando da utilizzare prima di lanciare 
   qualsiasi file 

--> .install/setup.bash

3) comandi principali : 

   ros2 run nome_package nome eseguibile
   ros2 launch nome_package nome eseguibile

comandi utili :
  ros2 topic list 


---------------------------------
ATTENZIONE!!!	
Il package prob3_pack è funzionante, ma utilizza dei file 
python per essere avviato...

il package packcpp non è viene buildato correttamente 
ma non è funzionante ancora, sarebbe la versione di packcpp 
in c++