#include <mylib/feature.h>

using namespace mylib;

Feature::Feature()
{

}

Feature::~Feature()
{

}

std::string Feature::toString() const
{
  return "Feature";
}

std::string Feature::work() const
{
  return "work";
}
