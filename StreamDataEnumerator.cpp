#include "StreamDataEnumerator.h"

namespace StreamDataIteratorSample {

    StreamDataEnumerator::StreamDataEnumerator(streambuf* streamBuffer)
        :dataType(StreamDataType::Data)
    {
        streamIterator = std::istreambuf_iterator<char>(streamBuffer);
        isMoveNextCalled = false;
    }

    bool StreamDataEnumerator::moveNext()
    {
        bool isDataPresent = false;

        while (streamIterator != eos && !isDataPresent) {
            ostringstream oss;
            while (*streamIterator != '\n') {
                if (*streamIterator == ':') {
                    if (setStreamDataType(oss.str())) {
                        isDataPresent = true;
                        *streamIterator++;
                        break;
                    }
                }
                oss << *streamIterator++;
            }
            *streamIterator++;
        }
        isMoveNextCalled = isDataPresent;
        return isDataPresent;
    }

    string StreamDataEnumerator::current()
    {
        ostringstream oss;
        if (isMoveNextCalled) {
            while (streamIterator != eos && *streamIterator != '\n') {
                oss << *streamIterator++;
            }
            isMoveNextCalled = false;
            currentObject = oss.str();
        }
        return currentObject;
    }

    bool StreamDataEnumerator::setStreamDataType(const string dataMarker)
    {
        bool isDataMarkerPresent = true;
        if (dataMarker.compare("data") == 0) {
            dataType = StreamDataType::Data;
        }
        else if (dataMarker.compare("error") == 0) {
            dataType = StreamDataType::Error;
        }
        else {
            isDataMarkerPresent = false;
        }

        return isDataMarkerPresent;
    }
}