#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gmp.h>
#include "paillier.c"

int main (int argc, char* argv[]){

  //aillier_plaintext_t* amt = paillier_plaintext_from_ui( atoi(argv[1]));
                                                                                                               
    paillier_pubkey_t* publicKey;
    publicKey = paillier_pubkey_from_hex("91b6a0c0e8374bac6d4e75f2497ff89f") ;
    
    unsigned int salary = strtoul(argv[1], NULL, 0);
    paillier_plaintext_t* amt = paillier_plaintext_from_ui( salary);
   paillier_ciphertext_t* encr;
   encr = paillier_enc(NULL, publicKey,amt,paillier_get_rand_devurandom); 
   char* result_string = mpz_get_str(NULL, 10, encr->c);
   printf("%s\n",result_string);
 
   return 0;				    

}
