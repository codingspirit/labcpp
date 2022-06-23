#include "aws/lab/os/unix/FileDescriptor.h"

#include <fcntl.h>
#include <unistd.h>

#include <atomic>

#include "aws/lab/utils/Logger.h"

namespace Aws::Lab::Os::Unix {
FileDescriptor::FileDescriptor() noexcept : mIsOpened{false}, mFd{0} {}

FileDescriptor::~FileDescriptor() {
    if (mIsOpened) {
        try {
            close();
        } catch (const std::ios_base::failure& e) {
            LOG_ERROR(e.what());
        }
    }
}

void FileDescriptor::open(std::string&& path, bool isReadOnly) {
    if (isReadOnly) {
        mFd = ::open(path.c_str(), O_RDONLY);
    } else {
        mFd = ::open(path.c_str(), O_RDWR);
    }

    if (mFd < 0) {
        throw std::ios_base::failure(
            fmt::format("Failed to close FileDescriptor {}", path));
    }

    mPath = std::forward<std::string>(path);
}

void FileDescriptor::close() {
    if (mIsOpened) {
        if (::close(mFd) != 0) {
            throw std::ios_base::failure(
                fmt::format("Failed to close FileDescriptor {}", mPath));
        }
        mIsOpened = false;
    }
}

std::streamsize FileDescriptor::read(uint8_t* buffer, std::size_t size) {
    std::streamsize readSize;

    if (mIsOpened) {
        readSize = ::read(mFd, buffer, size);
    } else {
        throw std::ios_base::failure(
                fmt::format("FileDescriptor {} is not opened", mPath));
    }

    return readSize;
}

std::streamsize FileDescriptor::write(const uint8_t* buffer, std::size_t size) {
    std::streamsize wroteSize;

    if (mIsOpened) {
        wroteSize = ::write(mFd, buffer, size);
    } else {
        throw std::ios_base::failure(
                fmt::format("FileDescriptor {} is not opened", mPath));
    }

    return wroteSize;
}

}  // namespace Aws::Lab::Os::Unix
