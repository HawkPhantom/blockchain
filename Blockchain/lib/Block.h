#ifndef BLOCK_H
#define BLOCK_H

#include "BlockHeaders.h"

class Block {
public:
    Block(const BlockHeaders& headers);

    //static void mineBlock(const Block& lastBlock);

    //get headers
    const BlockHeaders& getHeaders() const { return blockHeaders; }

private:
    BlockHeaders blockHeaders;
};

#endif // BLOCK_H
