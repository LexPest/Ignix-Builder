//
// Created by Alexey Mihailov on 2020-03-18.
//

#ifndef NERP_BUILDER_NBIOBSERVABLE_H
#define NERP_BUILDER_NBIOBSERVABLE_H

#include <vector>
#include <functional>

template <typename TObserver>
class nbIObservable
{
public:

    typedef size_t size_type;

    typedef std::vector<TObserver*> ObserverList;

    //*****************************************************************
    /// Add an observer to the list.
    //*****************************************************************
    void AddObserver(TObserver& observer)
    {
        // See if we already have it in our list.
        typename ObserverList::const_iterator i_observer = std::find(observer_list.begin(),
                                                                     observer_list.end(),
                                                                     &observer);

        // Not there?
        if (i_observer == observer_list.end())
        {
            // Add it.
            observer_list.push_back(&observer);
        }
    }

    //*****************************************************************
    /// Remove a particular observer from the list.
    //*****************************************************************
    void RemoveObserver(TObserver& observer)
    {
        // See if we have it in our list.
        typename ObserverList::iterator i_observer = std::find(observer_list.begin(),
                                                               observer_list.end(),
                                                               &observer);

        // Found it?
        if (i_observer != observer_list.end())
        {
            // Erase it.
            observer_list.erase(i_observer);
        }
    }

    //*****************************************************************
    /// Clear all observers from the list.
    //*****************************************************************
    void ClearObservers()
    {
        observer_list.clear();
    }

    //*****************************************************************
    /// Returns the number of observers.
    //*****************************************************************
    size_type NumberOfObservers() const
    {
        return observer_list.size();
    }

    //*****************************************************************
    /// Notify all of the observers, sending them the notification.
    /// TNotification is the notification type.
    //*****************************************************************
    template <typename TNotification>
    void NotifyObservers(TNotification n)
    {
        for (size_t i = 0; i < observer_list.size(); ++i)
        {
            observer_list[i]->Notification(n);
        }
    }

private:

    /// The list of observers.
    ObserverList observer_list;
};

#endif //NERP_BUILDER_NBIOBSERVABLE_H
