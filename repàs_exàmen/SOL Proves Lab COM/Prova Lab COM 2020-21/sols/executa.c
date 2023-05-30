#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/file.h>



int main (int argc, char * argv[])
{
   int res, status;
   int pid;
   char name_val[20];
   char name_html[20];

   if (argc != 2) {
      fprintf(stderr, "Us: %s <station-code>\n", argv[0]);
      exit(1);
   }

   sprintf (name_val, "%s.val", argv[1]);
   sprintf (name_html, "%s.html", argv[1]);
   
   //executa ./do-gen-plot name_val
   //Punt "A": crea un proces fill 
   pid = fork();//Punt "A"
   if (pid==0) {
      close(1);
      res = open (name_html, O_CREAT | O_TRUNC | O_WRONLY, 0644);
      if (res < 0) {
         perror ("open");
         exit(1);
      }

      //// Implementeu aquí l'execució del programa do-gen-plot,
      //// amb els paràmetres necessaris. 
      //Punt "B": canvi de la imatge del proces per a que executi do-gen-plot 
      //Punt "B"
    //
    //
      execlp ("./do-gen-plot", "./do-gen-plot", argv[1], NULL);

      perror ("error al intentar executar do-gen-plot");
      exit(1);
   }

   //Punt "C": el proces pare espera la mort del proces fill 
   res = waitpid(pid, &status, 0);
   if (res < 0) {
      perror ("error al esperar"); 
      exit(1);
   }

   return 0;
   

}
