#include "Relic.h"

Relic::Relic(Relic&& _other)
{
	buffer = _other.buffer;
}

Relic::Relic(Relic* _other)
{
	buffer = _other->buffer;
}
