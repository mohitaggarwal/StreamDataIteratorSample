#include <stdexcept>
#include <iostream>
#include <iterator>
#include <sstream>

using namespace std;

namespace StreamDataIteratorSample {
	
	enum class StreamDataType { Data, Error };

	class StreamDataEnumerator
	{
	private:
		bool isMoveNextCalled;
		string currentObject;
		std::istreambuf_iterator<char> eos; // end-of-range iterator
		std::istreambuf_iterator<char> streamIterator; // stream iterator
		enum StreamDataType dataType;

		bool setStreamDataType(const string dataMarker);

	public:
		StreamDataEnumerator(streambuf* streamBuffer);
		virtual ~StreamDataEnumerator() = default;

		bool moveNext();
		string current();

		const StreamDataType getDataType() const{ return dataType; }
	};
}