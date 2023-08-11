/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   JS.hpp                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mforstho <mforstho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/11 16:31:00 by mforstho      #+#    #+#                 */
/*   Updated: 2023/08/11 16:36:01 by mforstho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef JS_HPP
# define JS_HPP

class JS {
	private:
		unsigned int _latest_value = 0;
		unsigned int _latest_p2 = 1;
	public:
		JS(void);
		JS(JS const & src);
		virtual ~JS(void);
		JS & operator=(JS const & src);
		unsigned int next(void);
};



const JacobsthalSequenceWikipedia = struct {
    latest_value: usize = 0,
    latest_p2: usize = 1,

    const Self = @This();

    pub fn next(self: *Self) usize {
        self.latest_p2 <<= 1;
        self.latest_value = self.latest_p2 - self.latest_value;
        return self.latest_value;
    }
};

struct JacobsthalSequenceWikipedia {
	unsigned int latest_value = 0;
	unsigned int latest_p2 = 1;
}	t_js;

#endif
