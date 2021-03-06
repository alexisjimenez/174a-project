#include <stdlib.h>
#include <gmp.h>
#include <stdio.h>
#include <string.h>
<<<<<<< HEAD
//#include <mysql.h>
#include "paillier.h"
=======
#include <mysql.h>
#include "PLib/paillier.h"
>>>>>>> c38e768c2472dc1ace6078c91cdb1795ae63d42f

//The initializer of the function
my_bool SumHE_init(UDF_INIT *initid, UDF_ARGS *args,char *message)
{
  // The most important thing to do here is setting up the memory
  // you need...
  // Lets say we need a lonlong type variable to keep a checksum
  // Although we do not need one in this case

  paillier_ciphertext_t* sumHE = paillier_create_enc_zero();

  // store it as a char pointer in the pointer variable
  // Make sure that you don`t run in typecasting troubles later!!
  initid->ptr = (char*)sumHE;
        
  // check the arguments format
  if (args->arg_count != 1)
    {
      strcpy(message,"MyTest() requires one arguments");
      return 1;
    }

  if (args->arg_type[0] != INT_RESULT)
    {
      strcpy(message,"MyTest() requires an integer");
      return 1;
    }       
  return 0;            
}

//free the memory that was allocated in the initialization
void SumHE_deinit(UDF_INIT *initid)
{
  free(initid->ptr);  
}

//resets the sum to 0 for each new group
void MyTest_clear(UDF_INIT *initid, char *is_null, char *error)
{
  *((char*)initid->ptr) = 0;
}

//For each row, the current value is added to the sum, which is in the initid->ptr
void SUM_HE_add(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *error)
{
  paillier_pubkey_t* publicKey;
  publicKey = paillier_pubkey_from_hex("8be7f3e2c14d9bcf633376b12217cd1d") ;  

  paillier_ciphertext_t* sumHE = (paillier_ciphertext_t* )initid->ptr;

  paillier_ciphertext_t* decode0 = paillier_ciphertext_from_bytes( args->args[0], 128/8 );
spz_set


  paillier_mul(publicKey,sumHE,decode0,sumHE);  

}

//return the sum
char* Return_SumHE(UDF_INIT *initid, UDF_ARGS *args,char *result, unsigned long *length, char *is_null, char *error)
{

  paillier_ciphertext_t* sumHE = (paillier_ciphertext_t* )initid->ptr;
  return paillier_ciphertext_to_bytes(128/8,sumHE);
}
