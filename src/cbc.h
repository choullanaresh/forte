
#ifndef libcbc_h_
#define libcbc_h_

struct cbc_parameters;
struct cbc_master_key;
struct cbc_secret_key;
struct cbc_public_index;
struct cbc_encrypted_payload;
struct cbc_input;
struct cbc_output;

typedef struct cbc_parameters CBCParameters;
typedef struct cbc_master_key CBCMasterKey;
typedef struct cbc_secret_key CBCSecretKey;
typedef struct cbc_public_index CBCPublicIndex;
typedef struct cbc_encrypted_payload CBCEncryptedPayload;
typedef struct cbc_input CBCInput;
typedef struct cbc_output CBCOutput;

typedef enum {
	CBCScheme_BE,
	CBCScheme_IBE,
	CBCScheme_CPABE,
	CBCScheme_KPABE,
	CBCScheme_RSA,
}

typedef struct cbc_scheme {
	CBCParameters *(*Setup)(void);
	CBCMasterKey *(*CreateMasterKey)(const CBCParameters *parameters);
	CBCSecretKey *(*KeyGen)(const CBCMasterKey *masterKey, const CBCPublicIndex *index);
	CBCEncryptedPayload *(*Encrypt)(const CBCParameters, const CBCInput *input);
	CBCOutput *(*Decrypt)(const CBCSecretKey *secretKey, const CBCEncryptedPayload *encryptedPayload);
} CBCEncryptionScheme;

typedef struct cbc_scheme {
	CBCParameters *(*Setup)(void);
	CBCMasterKey *(*CreateMasterKey)(const CBCParameters *parameters);
	CBCSecretKey *(*KeyGen)(const CBCMasterKey *masterKey, const CBCPublicIndex *index);
	CBCEncryptedPayload *(*Sign)(const CBCParameters, const CBCInput *input);
	CBCOutput *(*Verify)(const CBCSecretKey *secretKey, const CBCEncryptedPayload *encryptedPayload);
} CBCSignatureScheme;


//(CBCParameters, CBCMasterKey) = Setup(parameter)
//CBCMasterKey = CreateMasterKey(CBCParameters)
//CBCSecretKey = KeyGen(CBCMasterKey, CBCPublicIndex)
//CBCEncryptedPayload = Encrypt(CBCPublicParameters, CBCInput)   
//CBCOutput = Decrypt(CBCSecretKey, CBCEncryptedPayload)    
//... y is the desired output of the function

// CBCIdentity

// CBCPublicKey
// CBCPrivateKey
// CBCMasterKey
// CBCParameters
// CBCIndex

// CBCKeyGenerator

// CBCBuffer
// CBCSignature

// CBCSigner
// CBCVerifier
// CBCEncryptor
// CNCDecryptor

// CBCScheme

#endif /* libcbc_h_ */

