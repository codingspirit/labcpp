#pragma once

#include <atomic>
#include <string>
#include <vector>
#include <ios>

#include "aws/lab/base/NonCopyable.h"

namespace Aws::Lab::Os::Unix {

/**
 * @brief Unix file descriptor.
 *
 */
class FileDescriptor : private Aws::Lab::Base::NonCopyable {
   public:
    FileDescriptor() noexcept;
    ~FileDescriptor();

    void open(std::string&& path, bool isReadOnly = true);

    void close();

    /**
     * @brief Read specific bytes from file descriptor.
     *
     * @param[in,out] buffer Target buffer to store read bytes.
     * @param[in] size Bytes to read.
     * @return std::streamsize If read operate completed successfully, return
     * the actual bytes read from file descriptor. If error happened, return the
     * error code defined in <errno.h>.
     */
    std::streamsize read(uint8_t* buffer, std::size_t size);

    /**
     * @brief Write specific bytes from file descriptor.
     *
     * @param[in] buffer Source buffer stores bytes to write.
     * @param[in] size Bytes to write.
     * @return std::streamsize If write operate completed successfully, return
     * the actual bytes wrote to file descriptor. If error happened, return the
     * error code defined in <errno.h>.
     */
    std::streamsize write(const uint8_t* buffer, std::size_t size);

   private:
    std::atomic<bool> mIsOpened;
    std::string mPath;
    int mFd;
};

}  // namespace Aws::Lab::Os::Unix
