#include  "Tree.h"

Tree::Tree() : L(), branch(0.2f, 0.07f), leaf(0.3), cone(0.2f, 0.07f) {
    L.apply_rules(4);
    std::cout << L.getAxiom() << std::endl;
}

void Tree::Draw(Shader shader, MatrixStack& MS) {
    std::vector<Component*>::iterator it = L.axiom.begin();
    glm::mat4 theMatrix(1.0f);
    for( ; it != L.axiom.end(); ++it) {
        if(!(*it)->isConstant()) {
            Value* temp = static_cast<Value*>(*it);
            if(temp->function != nullptr) {
                if((*it)->getSignifier() == 'F') {
                    //MS.addTransformation(theMatrix);
                    branch.Draw(shader, MS);
                    theMatrix = glm::mat4(1.0f);
                }
                MS.addTransformation((temp->function)(temp->parameter));
                //theMatrix = theMatrix*(temp->function)(temp->parameter);
            }
        }
        else {
            if((*it)->getSignifier() == '[') {
                MS.push();
                //theMatrix = glm::mat4(1.0f);
            }
            
            else if((*it)->getSignifier() == ']') {
                cone.Draw(shader, MS);
                MS.addTransformation(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.2f, 0.0f)));
                leaf.Draw(shader, MS);
                MS.pop();
                //theMatrix = glm::mat4(1.0f);
            }
        }
    }
}