#include "UnitTest++.h"
#include "System/file/cFileIStream.h"

namespace
{

TEST(IFileStreamDecl)
{
    yame::io::IFile* fooFile = NULL;
    yame::io::file_istream foo(*fooFile);
}

}

