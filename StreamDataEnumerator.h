#include <stdexcept>
#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

namespace StreamDataIteratorSample {
	class StreamDataEnumerator
	{
	private:
		bool isMoveNextCalled;
		string currentObject;
		string dataMarkerInStream;
		std::istreambuf_iterator<char> eos; // end-of-range iterator
		std::istreambuf_iterator<char> streamIterator; // stream iterator
	public:
		StreamDataEnumerator(streambuf* streamBuffer);
		virtual ~StreamDataEnumerator() = default;

		bool MoveNext();
		string Current();
	};
}