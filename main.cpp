#include "MantidHistogramData/HistogramBuilder.h"
#include "MantidJson/Json.h"
#include "MantidKernel/ArrayProperty.h"
#include "MantidParallel/IO/Chunker.h"
#include "MantidTypes/Core/DateAndTime.h"

#include "MantidBeamline/DetectorInfo.h"
#include "MantidGeometry/Surfaces/Cone.h"
#include "MantidIndexing/IndexInfo.h"
#include "MantidIndexing/Scatter.h"
#include "MantidIndexing/SpectrumIndexSet.h"

using Mantid::Kernel::V3D;
using namespace Mantid::HistogramData;
using namespace Mantid;
using namespace Geometry;
using namespace Mantid::Indexing;
using Beamline::DetectorInfo;

int main() {

  // types
  Mantid::Types::Core::DateAndTime d("1990-01-02T00:01:02.345");

  // json
  std::stringstream initialString("{\"bar\":2,\"baz\":3.1400000000000001,"
                                  "\"foo\":1,\"hello world\":\"HelloWorld\"}");
  Json::Value json;
  initialString >> json;
  auto mantid_json = Mantid::JsonHelpers::jsonToString(json);

  // kernel
  auto iProp = new Mantid::Kernel::ArrayProperty<int>("intProp");
  iProp->isDefault();

  // parallel
  const size_t chunkSize = 17;
  const Mantid::Parallel::IO::Chunker chunker(1, 0, {}, chunkSize);

  // histogram data
  HistogramBuilder builder;
  builder.setX(5);
  builder.setY(5);
  const auto hist = builder.build();

  // Indexing
  IndexInfo info(3);

  // Beamline
  std::unique_ptr<DetectorInfo> detInfo;
  detInfo = std::make_unique<DetectorInfo>();

  // geometry
  Cone A;
}