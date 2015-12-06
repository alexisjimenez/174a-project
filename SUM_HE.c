#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mysql.h>
#include <gmp.h>
#include "paillier.h"


 my_bool SUM_HE_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{        
  // check the arguments format
  if (args->arg_count != 1)
    {
      strcpy(message,"SUM_HE() requires one arguments");
      return 1;
    }
  
  if (args->arg_type[0] != STRING_RESULT)
    {
      strcpy(message,"SUM_HE() requires an string");
      return 1;
    }
  paillier_ciphertext_t* sumHE = paillier_create_enc_zero();
  initid->ptr = (char*)sumHE;       
  return 0;            
}

 void SUM_HE_deinit(UDF_INIT *initid)
{
  // Here you have to free the memory you allocated in the 
  // initialization function
  free(initid->ptr);
  
        
}

void SUM_HE_clear(UDF_INIT *initid, char *is_null, char *error)
{
  paillier_ciphertext_t* sumHE = (paillier_ciphertext_t*)initid->ptr ;
  //free the cipher text because of c
  paillier_freeciphertext(sumHE);
  //set to 0
  sumHE = paillier_create_enc_zero();
    
}

void SUM_HE_add(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *error)
{       
  //get a hard copy of the public key that was generated 
  paillier_pubkey_t* publicKey;
  publicKey = paillier_pubkey_from_hex("91b6a0c0e8374bac6d4e75f2497ff89f");
  //create ciphertext where the encrypted sum will be stored
  paillier_ciphertext_t* sumHE = (paillier_ciphertext_t*)initid->ptr ;
  paillier_ciphertext_t*  decodeInput = (paillier_ciphertext_t*) malloc(sizeof(paillier_ciphertext_t));
  mpz_init_set_str(decodeInput->c, args->args[0], 10);
  paillier_mul(hard_public_key,sumHE,decodeInput,sumHE);
  //free the temp ciphertext and public key
  paillier_freepubkey(publicKey);
  paillier_freeciphertext(decodeInput);
        
}
 char* SUM_HE(UDF_INIT *initid, UDF_ARGS *args,char *result, unsigned long *length, char *is_null, char *error)
{ 
  //create a cipher text that carries the encrypted sum
  paillier_ciphertext_t* sumHE = (paillier_ciphertext_t*)initid->ptr ;
  //turn to string and return     
  char* sum_string = mpz_get_str (NULL, 10, sum->c);
  *length = strlen(sum_string);
  return sum_string;
            
}



