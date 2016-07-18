
#pragma once

#include "../NetworkSpec.hpp"
#include <cassert>
#include <vector>

namespace neuralnetwork {
namespace rnn {

struct LayerConnection {
  unsigned srcLayerId;
  unsigned dstLayerId;

  int timeOffset; // should be <= 0

  LayerConnection(unsigned srcLayerId, unsigned dstLayerId, int timeOffset)
      : srcLayerId(srcLayerId), dstLayerId(dstLayerId), timeOffset(timeOffset) {
    assert(timeOffset == 0 || timeOffset == -1);
  }

  bool operator==(const LayerConnection &other) {
    return this->srcLayerId == other.srcLayerId && this->dstLayerId == other.dstLayerId &&
           this->timeOffset == other.timeOffset;
  }
};

struct LayerSpec {
  unsigned uid; // must be >= 1, 0 is the "input" layer.
  unsigned numNodes;
  bool isOutput;

  std::vector<LayerConnection> inConnections;

  LayerSpec(unsigned uid, unsigned numNodes, bool isOutput,
            const std::vector<LayerConnection> &inConnections)
      : uid(uid), numNodes(numNodes), isOutput(isOutput), inConnections(inConnections) {
    assert(uid >= 1);
    assert(numNodes > 0);
    assert(inConnections.size() > 0);
  }
};

struct RNNSpec {
  unsigned numInputs;
  unsigned numOutputs;
  std::vector<LayerSpec> layers;

  LayerActivation hiddenActivation;
  LayerActivation outputActivation;

  float nodeActivationRate; // for dropout regularization.
};
}
}
