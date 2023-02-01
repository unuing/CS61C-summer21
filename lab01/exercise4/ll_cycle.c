#include <stddef.h>
#include <stdbool.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* TODO: Implement ll_has_cycle */
    node *fast_ptr = head;
    node *slow_ptr = head;
    while (fast_ptr) {
        if (fast_ptr->next) {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        } else {
            return false;
        }
        if (fast_ptr == slow_ptr) {
            return true;
        }
    }
    return false;
}
