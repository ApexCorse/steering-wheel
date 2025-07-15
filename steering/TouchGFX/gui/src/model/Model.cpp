#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

Model::Model() : modelListener(0), configuration(nullptr), chosenSection(""), chosenModule("")
{
  configuration = new Configuration();
}

void Model::tick()
{

}
