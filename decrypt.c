#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gmp.h>
#include "paillier.c"
int main (int argc, char* argv[]){
    //GET ENCRYPTED VALUE
    paillier_ciphertext_t* eAmt = (paillier_ciphertext_t*) malloc(sizeof(paillier_ciphertext_t));
    mpz_init_set_str(eAmt->c,argv[1],10);
 
   //GET PUBLIC AND PRIVATE KEY  
    paillier_pubkey_t* publicKey;
    publicKey = paillier_pubkey_from_hex("91b6a0c0e8374bac6d4e75f2497ff89f") ;

    paillier_prvkey_t* privateKey;
    privateKey = paillier_prvkey_from_hex("e9243467d9f212ab0865c14c086c9b4",publicKey) ;

    //DECRYPTION
   paillier_plaintext_t* decr;
   decr = paillier_dec(NULL,publicKey, privateKey,eAmt); 
   int dAmt = mpz_get_ui(decr->m);
   printf("%d\n",dAmt);
}
