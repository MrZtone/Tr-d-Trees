#include  "Tree.h"

Tree::Tree() : L(), branch(1.0f, 0.07f), leaf(0.3), cone(0.2f, 0.07f) {
    L.apply_rules(4);
    std::cout << L.getAxiom() << std::endl;
}

void Tree::Draw(Shader shader, MatrixStack& MS) {
    std::vector<Component>::iterator it = L.axiom.begin();
    for( ; it != L.axiom.end(); ++it) {
        
        if((*it).getSignifier() == 'F') {
            MS.push();
            MS.addTransformation(glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, (float)(*it).parameter, 1.0f)));
            branch.Draw(shader, MS);
            MS.pop();
        }

        else if((*it).getSignifier() == '[') {
            MS.push();
        }
        
        else if((*it).getSignifier() == ']') {
            cone.Draw(shader, MS);
            MS.addTransformation(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.2f, 0.0f)));
            leaf.Draw(shader, MS);
            MS.pop();
        }

        if((*it).function != nullptr) {
            MS.addTransformation(((*it).function)((*it).parameter));
        }
    }
}