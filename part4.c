#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef _WIN_
typedef unsigned __int64 ulonglong;     /* Microsofts 64 bit types */
typedef __int64 longlong;
#else
typedef unsigned long long ulonglong;
typedef long long longlong;
#endif /*__WIN__*/
#include <mysql.h>
//static pthread_mutex_t LOCK_hostname;

#ifdef __cplusplus
//The initializer of the function
extern "C" my_bool MyTest_init(UDF_INIT *initid, UDF_ARGS *args,char *message)
{
  // The most important thing to do here is setting up the memory
  // you need...
  // Lets say we need a lonlong type variable to keep a checksum
  // Although we do not need one in this case

  longlong* i = new longlong; // create the variable
  *i = 0;                     // set it to a value
        
  // store it as a char pointer in the pointer variable
  // Make sure that you don`t run in typecasting troubles later!!
  initid->ptr = (char*)i;
        
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
extern "C" void MyTest_deinit(UDF_INIT *initid)
{
  delete (longlong*)initid->ptr;
}
#endif

//resets the sum to 0 for each new group
void MyTest_clear(UDF_INIT *initid, char *is_null, char *error)
{
  *((longlong*)initid->ptr) = 0;
}

//For each row, the current value is added to the sum, which is in the initid->ptr
void MyTest_add(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *error)
{
  //here call the homoadd function from paillier
  *((longlong*)initid->ptr) =  *((longlong*)initid->ptr) +  *((longlong*)args->args[0]);
}

//return the sum
longlong MyTest(UDF_INIT *initid, UDF_ARGS *args, char *is_null, char *error)
{
  return *((longlong*)initid->ptr);
}
