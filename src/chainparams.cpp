// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//
// Main network
// Coding-Jewelry: Rime parameters
//
class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x2d;
        pchMessageStart[1] = 0x3f;
        pchMessageStart[2] = 0xa2;
        pchMessageStart[3] = 0xf5;

        vAlertPubKey = ParseHex("04eece7b75948d5a57ad17248129d64b8d37db9b130f4e8cb85a7600fc52558b6e82a20ad2f88f5f1dbab1e1123c064dd3e3f932ba332dffd9356fe73c82beda45");
        
        nDefaultPort = 51395;
        nRPCPort = 51394;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 18);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 18);

        const char* pszTimestamp = "And when I think of giving up, I remember the reasons that made you stand by now!";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].nValue = nGenesisBlockReward;
        vout[0].SetEmpty();
        CTransaction txNew(1, 1535308190, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1535308190;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 857701;

        hashGenesisBlock = genesis.GetHash();
        
        assert(hashGenesisBlock == uint256("0x041631da25cd31703337058fc00f4381cbe62331a59a455931fd294e4effd97d"));
        assert(genesis.hashMerkleRoot == uint256("0xaf949a75b09cf75c89723051d77af647890382bdde1ead82688c66842ff1d9c2"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,50);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,5);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,50 + 128);
        base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1,40);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();

        // Coding-Jewelry: Rime parameters: rm vseeds

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nPoolMaxTransactions = 3;
        strAnonsendPoolDummyAddress = "MLJoZZky8GtfYKiRY2Jzxfd4KTEK3drZv2";
        nEndPoWBlock = 0x7fffffff;
        nStartPoSBlock = 0;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
// Coding-Jewelry: Rime parameters
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x70;
        pchMessageStart[1] = 0x35;
        pchMessageStart[2] = 0x22;
        pchMessageStart[3] = 0x05;

        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        bnProofOfStakeLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("04da6ac103778f420a56c8d3b47133ad05872a6eeae68a29e765d4d98b8273361fd0bc7cab6fa28463611b852cfca06afd41e8dab8ce48736763c07d2015736469");
        nDefaultPort = 41315;
        nRPCPort = 41314;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime    = 1535308154;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 857701;

        hashGenesisBlock = genesis.GetHash();

	    // assert(hashGenesisBlock == uint256("0x041631da25cd31703337058fc00f4381cbe62331a59a455931fd294e4effd97d"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,111);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,196);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1,324);
        base58Prefixes[STEALTH_ADDRESS] = std::vector<unsigned char>(1,40);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        nEndPoWBlock = 0x7fffffff;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;

//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0x2f;
        pchMessageStart[1] = 0xca;
        pchMessageStart[2] = 0x4d;
        pchMessageStart[3] = 0x3e;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        genesis.nTime = 1498159985;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 857701;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 31315;
        strDataDir = "regtest";
	// assert(hashGenesisBlock == uint256("0x041631da25cd31703337058fc00f4381cbe62331a59a455931fd294e4effd97d"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
