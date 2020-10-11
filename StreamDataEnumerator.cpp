#include <sstream>
#include "StreamDataEnumerator.h"

namespace StreamDataIteratorSample {

    StreamDataEnumerator::StreamDataEnumerator(streambuf* streamBuffer)
    {
        streamIterator = std::istreambuf_iterator<char>(streamBuffer);
        dataMarkerInStream = "data: ";
    }

    bool StreamDataEnumerator::MoveNext()
    {
        bool isDataPresent = false;
        int currentPos = 0;
        int markerLength = dataMarkerInStream.length();

        while (streamIterator != eos) {
            if (dataMarkerInStream[currentPos] == *streamIterator) {
                if (currentPos >= markerLength - 1) {
                    isDataPresent = true;
                    *streamIterator++;
                    break;
                }
                else {
                    currentPos++;
                }
            }
            else {
                currentPos = 0;
            }
            *streamIterator++;
        }

        return isDataPresent;
    }

    string StreamDataEnumerator::Current()
    {
        ostringstream oss;
        while (streamIterator != eos && *streamIterator != '\n') {
            oss << *streamIterator++;
        }
        return oss.str();
    }
}