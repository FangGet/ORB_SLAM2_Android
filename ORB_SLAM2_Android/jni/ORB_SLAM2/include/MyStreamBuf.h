#include <iostream>
#include <streambuf>
#include <android/log.h>

class MyStreamBuf : public std::streambuf
{
    enum
    {
        BUFFER_SIZE = 255,
    };

public:
    MyStreamBuf()
    {
        buffer_[BUFFER_SIZE] = '\0';
        setp(buffer_, buffer_ + BUFFER_SIZE - 1);
    }

    ~MyStreamBuf()
    {
        sync();
    }

protected:
    virtual int_type overflow(int_type c)
    {
        if (c != EOF)
        {
            *pptr() = c;
            pbump(1);
        }
        flush_buffer();
        return c;
    }

    virtual int sync()
    {
        flush_buffer();
        return 0;
    }

private:
    int flush_buffer()
    {
        int len = int(pptr() - pbase());
        if (len <= 0)
            return 0;

        if (len <= BUFFER_SIZE)
            buffer_[len] = '\0';

#ifdef ANDROID
        android_LogPriority t = ANDROID_LOG_INFO;
        __android_log_write(t, "mylog", buffer_);
#else
        printf("%s", buffer_);
#endif

        pbump(-len);
        return len;
    }

private:
    char buffer_[BUFFER_SIZE + 1];
};
