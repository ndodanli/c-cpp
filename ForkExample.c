#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
void main() {
    pid_t pid;
    pid = getpid();
    printf("Parent process başlatıldı\n");
    printf("Parent process id:%d\n",pid);
     pid = fork();
     if (pid == 0){
          ChildProcess(pid);
     }
     else{
          wait(NULL);
          ParentProcess();
     }
}
void  ChildProcess(pidFork)
{
    pid_t pid;
    pid = getpid();
    long int sayi;
    printf("Child process başlatıldı\n");
    printf("Child process id:%d\n",pid);
    printf("Fork id:%d\n",pidFork);
	printf("Pozitif bir sayı giriniz\n");
    scanf("%ld", &sayi);
    int sayac=1,sayiMax=1;
            while(sayi>1)
            {
                if (sayi % 2 == 0)
                {
                    sayi = sayi / 2;
                }
                else
                {
                    sayi = sayi * 3 + 1;
                }
                if (sayi > sayiMax) sayiMax = sayi;
                sayac++;
            }
            printf("%ld sayısı %d adımda 1'e indirgendi.\n",sayi,sayac);
            printf("Adımlar içinde bulunan en büyük sayı:%d\n",sayiMax);
}

void  ParentProcess()
{
    pid_t pid;
    pid = getpid();
    printf("Parent process'e dönüldü'");
    printf("Parent process id:%d\n",pid);
    printf("Parent process sona erdi");
}