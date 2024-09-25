#include <cstring>
#include <string>
#include "archivo_gorriti.h"


gorriti_archivo::gorriti_archivo(){

   _nombre_archivo="matias.datos";


}


bool gorriti_archivo::guardar_archivo(gorriti &registro){
FILE *pfile;
bool resultado;

     pfile=fopen(_nombre_archivo.c_str(),"ab");

       if(pfile==nullptr){
        return false;

       }

    if(fwrite(&registro,sizeof(gorriti),1,pfile)==1){

        resultado=fwrite(&registro,sizeof(gorriti),1,pfile);


    }
        return resultado;


     }

     gorriti gorriti_archivo::leer_archivo(int posicion){

     FILE *pfile;
     gorriti registro;

      if(pfile==nullptr){
        return registro;

       }

    pfile=fopen(_nombre_archivo.c_str(),"rb");

    fseek(pfile,sizeof(gorriti) * posicion,SEEK_SET);
    fread(&registro,sizeof(gorriti),1,pfile);

     fclose(pfile);

     return registro;


     }


int gorriti_archivo::get_cantidad_archivo(){

   int total,cantidad;
     FILE *pfile;



    pfile=fopen(_nombre_archivo.c_str(),"rb");

 if(pfile==nullptr){
        return 0;

       }

fseek(pfile,0,SEEK_END);
total=ftell(pfile);

  fclose(pfile);

   return total/sizeof(gorriti);

}
