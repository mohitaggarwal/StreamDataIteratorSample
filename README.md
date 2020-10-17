# StreamDataIteratorSample

## StreamDataEnumerator
### Constructor
`StreamDataEnumerator(streambuf* streamBuffer)`
### Public methods
```
bool MoveNext();
string Current();
```

Initiate the StreamDataEnumerator with the stream buffer. Use MoveNext method to check if there exist any data in stream and if exist then read using Current method. 

StreamDataEnumerator will check for data marker (for example by default it is "data: ") in stream and move the pointer to after data marker position. On Current method call, it will read the data till next line and return the string

Sample input can be found under TestSamples folder.

## Example use of StreamDataEnumerator:
```
StreamDataEnumerator dataEnumerator = StreamDataEnumerator(streamBuffer);
while (dataEnumerator.MoveNext()) {
    string data = dataEnumerator.Current();
    if (streamDataType == StreamDataType::Data)
    {
	cout << data << endl;
    }
    else if (streamDataType == StreamDataType::Error)
    {
        // Do the operation for error stream data
    }
}

```
## Sample Input:
```
data: {"name": "abc1"}

data: {"name": "abc2"}

data: {"name": "abc3"}


```
## Sample Output on calling StreamDataEnumerator.Current in loop:
```
{"name": "abc1"}
{"name": "abc2"}
{"name": "abc3"}
```
