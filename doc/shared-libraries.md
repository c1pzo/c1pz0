Shared Libraries
================

## c1pzoconsensus

The purpose of this library is to make the verification functionality that is critical to C1pzo's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `c1pzoconsensus.h` located in `src/script/c1pzoconsensus.h`.

#### Version

`c1pzoconsensus_version` returns an `unsigned int` with the API version *(currently `1`)*.

#### Script Validation

`c1pzoconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `c1pzoconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `c1pzoconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `c1pzoconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/c1pzo/bips/blob/master/bip-0016.mediawiki)) subscripts
- `c1pzoconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/c1pzo/bips/blob/master/bip-0066.mediawiki)) compliance
- `c1pzoconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY` - Enforce NULLDUMMY ([BIP147](https://github.com/c1pzo/bips/blob/master/bip-0147.mediawiki))
- `c1pzoconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY` - Enable CHECKLOCKTIMEVERIFY ([BIP65](https://github.com/c1pzo/bips/blob/master/bip-0065.mediawiki))
- `c1pzoconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY` - Enable CHECKSEQUENCEVERIFY ([BIP112](https://github.com/c1pzo/bips/blob/master/bip-0112.mediawiki))
- `c1pzoconsensus_SCRIPT_FLAGS_VERIFY_WITNESS` - Enable WITNESS ([BIP141](https://github.com/c1pzo/bips/blob/master/bip-0141.mediawiki))

##### Errors
- `c1pzoconsensus_ERR_OK` - No errors with input parameters *(see the return value of `c1pzoconsensus_verify_script` for the verification status)*
- `c1pzoconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `c1pzoconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `c1pzoconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`
- `c1pzoconsensus_ERR_AMOUNT_REQUIRED` - Input amount is required if WITNESS is used
- `c1pzoconsensus_ERR_INVALID_FLAGS` - Script verification `flags` are invalid (i.e. not part of the libconsensus interface)

### Example Implementations
- [NC1pzo](https://github.com/MetacoSA/NC1pzo/blob/5e1055cd7c4186dee4227c344af8892aea54faec/NC1pzo/Script.cs#L979-#L1031) (.NET Bindings)
- [node-libc1pzoconsensus](https://github.com/bitpay/node-libc1pzoconsensus) (Node.js Bindings)
- [java-libc1pzoconsensus](https://github.com/dexX7/java-libc1pzoconsensus) (Java Bindings)
- [c1pzoconsensus-php](https://github.com/Bit-Wasp/c1pzoconsensus-php) (PHP Bindings)
