#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int pipeFileDescriptor[2];
	int returnPipe = pipe(pipeFileDescriptor);
	char writeMessages [1][20] = {"Mensagem 1"};
	char readMessages [20];
	int pid = fork();

	if (returnPipe == -1) {
		printf("Erro");
		return 1;
	}

	if (pid > 0) {
		//pai
		printf("Writing message 1 is: %s\n", writeMessages[0]);
		write(pipeFileDescriptor[1], writeMessages[0], sizeof(char) * 20);
        }
         
	else if (pid == 0) {
		//filho
		read(pipeFileDescriptor[0], readMessages, sizeof(char) * 20);
		printf("Reading message 1 is: %s\n", readMessages);
		exit(0);
 	}
  return 0;
}
