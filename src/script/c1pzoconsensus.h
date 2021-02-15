// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2020-2021 The C1pzo Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef C1PZO_SCRIPT_C1PZOCONSENSUS_H
#define C1PZO_SCRIPT_C1PZOCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_C1PZO_INTERNAL) && defined(HAVE_CONFIG_H)
#include <config/c1pzo-config.h>
  #if defined(_WIN32)
    #if defined(HAVE_DLLEXPORT_ATTRIBUTE)
      #define EXPORT_SYMBOL __declspec(dllexport)
    #else
      #define EXPORT_SYMBOL
    #endif
  #elif defined(HAVE_DEFAULT_VISIBILITY_ATTRIBUTE)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBC1PZOCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define C1PZOCONSENSUS_API_VER 1

typedef enum c1pzoconsensus_error_t
{
    c1pzoconsensus_ERR_OK = 0,
    c1pzoconsensus_ERR_TX_INDEX,
    c1pzoconsensus_ERR_TX_SIZE_MISMATCH,
    c1pzoconsensus_ERR_TX_DESERIALIZE,
    c1pzoconsensus_ERR_AMOUNT_REQUIRED,
    c1pzoconsensus_ERR_INVALID_FLAGS,
} c1pzoconsensus_error;

/** Script verification flags */
enum
{
    c1pzoconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    c1pzoconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    c1pzoconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    c1pzoconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    c1pzoconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    c1pzoconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    c1pzoconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    c1pzoconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = c1pzoconsensus_SCRIPT_FLAGS_VERIFY_P2SH | c1pzoconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               c1pzoconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | c1pzoconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               c1pzoconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | c1pzoconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int c1pzoconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, c1pzoconsensus_error* err);

EXPORT_SYMBOL int c1pzoconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, c1pzoconsensus_error* err);

EXPORT_SYMBOL unsigned int c1pzoconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // C1PZO_SCRIPT_C1PZOCONSENSUS_H
