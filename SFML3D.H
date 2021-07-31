#pragma once

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")
#include <iostream>
#include <vector>
#include "DataImpl.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GLU.h>

namespace sf
{

    class Transformable3D;
	
	struct Transform3D
	{

        friend class Transformable3D;
		
	public:
        Transform3D() :
            m_origin(0, 0, 0),
            m_position(0, 0, 0),
            m_rotation(0, 0, 0),
            m_scale(1, 1, 1),
            m_color(255, 255, 255, 255)
        {

        }

	
    protected:

        ////////////////////////////////////////////////////////////
        // Member data
        ////////////////////////////////////////////////////////////
        mutable Vector3<GLfloat>          m_origin;                     ///< Origin of translation/rotation/scaling of the object
        mutable Vector3<GLfloat>          m_position;                   ///< Position of the object in the 2D world
        mutable Vector3<GLfloat>          m_rotation;                   ///< Orientation of the object, in degrees
        mutable Vector3<GLfloat>          m_scale;                      ///< Scale of the object
        mutable Color                         m_color;
	};

	
    ////////////////////////////////////////////////////////////
    /// \brief Decomposed transform defined by a position, a rotation and a scale
    ///
    ////////////////////////////////////////////////////////////
    class Transformable3D : public Transform3D
    {

    public:
        ////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        ////////////////////////////////////////////////////////////
        Transformable3D() :
            Transform3D()
        {
	        
        }

        ////////////////////////////////////////////////////////////
        /// \brief Virtual destructor
        ///
        ////////////////////////////////////////////////////////////
        virtual ~Transformable3D() = default;

        ////////////////////////////////////////////////////////////
        /// \brief set the position of the object
        ///
        /// This function completely overwrites the previous position.
        /// See the move function to apply an offset based on the previous position instead.
        /// The default position of a Transformable3D object is (0, 0, 0).
        ///
        /// \param x X coordinate of the new position
        /// \param y Y coordinate of the new position
        /// \param z Z coordinate of the new position
        ///
        /// \see move, getPosition
        ///
        ////////////////////////////////////////////////////////////
        void setPosition(const GLfloat x, const GLfloat y, const GLfloat z) const
        {
            m_position = { x, y, z };
        }

        ////////////////////////////////////////////////////////////
        /// \brief set the position of the object
        ///
        /// This function completely overwrites the previous position.
        /// See the move function to apply an offset based on the previous position instead.
        /// The default position of a Transformable3D object is (0, 0, 0).
        ///
        /// \param position New position
        ///
        /// \see move, getPosition
        ///
        ////////////////////////////////////////////////////////////
        void setPosition(const Vector3<GLfloat>& position) const
        {
            m_position = position;
        }

        ////////////////////////////////////////////////////////////
        /// \brief set the orientation of the object
        ///
        /// This function completely overwrites the previous rotation.
        /// See the rotate function to add an angle based on the previous rotation instead.
        /// The default rotation of a Transformable3D object is (0, 0, 0).
        ///
        /// \param x (pitch) New rotation x, in degrees
        /// \param y (yaw) New rotation y, in degrees
        /// \param z (roll) New rotation z, in degrees
        ///
        /// \see rotate, getRotation
        ///
        ////////////////////////////////////////////////////////////
        void setRotation(const GLfloat x, const GLfloat y, const GLfloat z) const
        {
            this->m_rotation = { x, y, z };
        }

        ////////////////////////////////////////////////////////////
        /// \brief set the scale factors of the object
        ///
        /// This function completely overwrites the previous scale.
        /// See the scale function to add a factor based on the previous scale instead.
        /// The default scale of a Transformable3D object is (1, 1, 1).
        ///
        /// \param factorX New horizontal scale factor
        /// \param factorY New vertical scale factor
        /// \param factorZ New z scale factor
        ///
        /// \see scale, getScale
        ///
        ////////////////////////////////////////////////////////////
        void setScale(const GLfloat factorX, const GLfloat factorY, const GLfloat factorZ) const
        {
            m_scale = { factorX, factorY, factorZ };
        }

        ////////////////////////////////////////////////////////////
        /// \brief set the scale factors of the object
        ///
        /// This function completely overwrites the previous scale.
        /// See the scale function to add a factor based on the previous scale instead.
        /// The default scale of a Transformable3D object is (1, 1, 1).
        ///
        /// \param factors New scale factors
        ///
        /// \see scale, getScale
        ///
        ////////////////////////////////////////////////////////////
        void setScale(const Vector3<GLfloat>& factors) const
        {
            m_scale = factors;
        }

        ////////////////////////////////////////////////////////////
        /// \brief set the local origin of the object
        ///
        /// The origin of an object defines the center point for
        /// all transformations (position, scale, rotation).
        /// The coordinates of this point must be relative to the
        /// top-left corner of the object, and ignore all
        /// transformations (position, scale, rotation).
        /// The default origin of a Transformable3D object is (0, 0, 0).
        ///
        /// \param x X coordinate of the new origin
        /// \param y Y coordinate of the new origin
        /// \param z Z coordinate of the new origin
        ///
        /// \see getOrigin
        ///
        ////////////////////////////////////////////////////////////
        void setOrigin(const GLfloat x, const GLfloat y, const GLfloat z) const
        {
            m_origin = { x, y, z };
        }

        ////////////////////////////////////////////////////////////
        /// \brief set the local origin of the object
        ///
        /// The origin of an object defines the center point for
        /// all transformations (position, scale, rotation).
        /// The coordinates of this point must be relative to the
        /// top-left corner of the object, and ignore all
        /// transformations (position, scale, rotation).
        /// The default origin of a Transformable3D object is (0, 0, 0).
        ///
        /// \param origin New origin
        ///
        /// \see getOrigin
        ///
        ////////////////////////////////////////////////////////////
        void setOrigin(const Vector3<GLfloat>& origin) const
        {
            m_origin = origin;
        }

        ////////////////////////////////////////////////////////////
        /// \brief get the position of the object
        ///
        /// \return Current position
        ///
        /// \see setPosition
        ///
        ////////////////////////////////////////////////////////////
        const Vector3<GLfloat>& getPosition() const
        {
            return m_position;
        }

        ////////////////////////////////////////////////////////////
        /// \brief get the orientation of the object
        ///
        /// The rotation is always in the range [0, 360].
        ///
        /// \return Current rotation, in degrees
        ///
        /// \see setRotation
        ///
        ////////////////////////////////////////////////////////////
        const Vector3<GLfloat>& getRotation() const
        {
            return m_rotation;
        }

        ////////////////////////////////////////////////////////////
        /// \brief get the current scale of the object
        ///
        /// \return Current scale factors
        ///
        /// \see setScale
        ///
        ////////////////////////////////////////////////////////////
        const Vector3<GLfloat>& getScale() const
        {
            return m_scale;
        }

        ////////////////////////////////////////////////////////////
        /// \brief get the local origin of the object
        ///
        /// \return Current origin
        ///
        /// \see setOrigin
        ///
        ////////////////////////////////////////////////////////////
        const Vector3<GLfloat>& getOrigin() const
        {
            return m_origin;
        }

        ////////////////////////////////////////////////////////////
        /// \brief Move the object by a given offset
        ///
        /// This function adds to the current position of the object,
        /// unlike setPosition which overwrites it.
        /// Thus, it is equivalent to the following code:
        /// \code
        /// sf::Vector3<_Value_type> pos = object.getPosition();
        /// object.setPosition(pos.x + offsetX, pos.y + offsetY);
        /// \endcode
        ///
        /// \param offsetX X offset
        /// \param offsetY Y offset
        /// \param offsetZ Z offset
        ///
        /// \see setPosition
        ///
        ////////////////////////////////////////////////////////////
        void move(const GLfloat offsetX, const GLfloat offsetY, const GLfloat offsetZ) const
        {
            m_position.x += offsetX;
            m_position.y += offsetY;
            m_position.z += offsetZ;
        }

        ////////////////////////////////////////////////////////////
        /// \brief Move the object by a given offset
        ///
        /// This function adds to the current position of the object,
        /// unlike setPosition which overwrites it.
        /// Thus, it is equivalent to the following code:
        /// \code
        /// object.setPosition(object.getPosition() + offset);
        /// \endcode
        ///
        /// \param offset Offset
        ///
        /// \see setPosition
        ///
        ////////////////////////////////////////////////////////////
        void move(const Vector3<GLfloat>& offset) const
        {
            m_position.x += offset.x;
            m_position.y += offset.y;
            m_position.z += offset.z;
        }

        ////////////////////////////////////////////////////////////
        /// \brief Rotate the object
        ///
        /// This function adds to the current rotation of the object,
        /// unlike setRotation which overwrites it.
        /// Thus, it is equivalent to the following code:
        /// \code
        /// object.setRotation(object.getRotation() + angle);
        /// \endcode
        ///
        /// \param x (pitch) Angle of rotation x, in degrees
        /// \param y (yaw) Angle of rotation x, in degrees
        /// \param z (roll) Angle of rotation x, in degrees
        ///
        ////////////////////////////////////////////////////////////
        void rotate(const GLfloat x, const GLfloat y, const GLfloat z) const
        {
            m_rotation.x += x;
            m_rotation.y += y;
            m_rotation.z += z;
        }

        ////////////////////////////////////////////////////////////
        /// \brief Rotate the object
        ///
        /// This function adds to the current rotation of the object,
        /// unlike setRotation which overwrites it.
        /// Thus, it is equivalent to the following code:
        /// \code
        /// object.setRotation(object.getRotation() + angle);
        /// \endcode
        ///
        /// \param angles Angle of rotation x, in degrees
        /// 
        ////////////////////////////////////////////////////////////	
        void rotate(const Vector3<GLfloat> angles) const
        {
            m_rotation.x += angles.x;
            m_rotation.y += angles.y;
            m_rotation.z += angles.z;
        }

        ////////////////////////////////////////////////////////////
        /// \brief Scale the object
        ///
        /// This function multiplies the current scale of the object,
        /// unlike setScale which overwrites it.
        /// Thus, it is equivalent to the following code:
        /// \code
        /// sf::Vector3<_Value_type> scale = object.getScale();
        /// object.setScale(scale.x * factorX, scale.y * factorY);
        /// \endcode
        ///
        /// \param factorX Horizontal scale factor
        /// \param factorY Vertical scale factor
        /// \param factorZ Z scale factor
        ///
        /// \see setScale
        ///
        ////////////////////////////////////////////////////////////
        void scale(const GLfloat factorX, const GLfloat factorY, const GLfloat factorZ) const
        {
            m_scale.x += factorX;
            m_scale.y += factorY;
            m_scale.z += factorZ;
        }

        ////////////////////////////////////////////////////////////
        /// \brief Scale the object
        ///
        /// This function multiplies the current scale of the object,
        /// unlike setScale which overwrites it.
        /// Thus, it is equivalent to the following code:
        /// \code
        /// sf::Vector3<_Value_type> scale = object.getScale();
        /// object.setScale(scale.x * factor.x, scale.y * factor.y);
        /// \endcode
        ///
        /// \param factor Scale factors
        ///
        /// \see setScale
        ///
        ////////////////////////////////////////////////////////////
        void scale(const Vector3<GLfloat>& factor) const
        {
            m_scale.x += factor.x;
            m_scale.y += factor.y;
            m_scale.z += factor.z;
        }

        ////////////////////////////////////////////////////////////
        /// \brief get the combined transform of the object
        ///
        /// \return Transform combining the position/rotation/scale/origin of the object
        ///
        /// \see getInverseTransform
        ///
        ////////////////////////////////////////////////////////////

        void setPitch(const GLfloat pitch) const
        {
            m_rotation.x = pitch;
        }

        void setYaw(const GLfloat yaw) const
        {
            m_rotation.y = yaw;
        }

        void setRoll(const GLfloat roll) const
        {
            m_rotation.z = roll;
        }

        GLfloat& getPitch() const
        {
            return m_rotation.x;
        }

        GLfloat& getYaw() const
        {
            return m_rotation.y;
        }

        GLfloat& getRoll() const
        {
            return m_rotation.z;
        }

        void setFillColor(sf::Color& color) const
        {
            m_color = color;
        }

        void setFillColor(const GLubyte r, const GLubyte g, const GLubyte b, const GLubyte a = 255) const
        {
            m_color.r = r;
            m_color.g = g;
            m_color.b = b;
            m_color.a = a;
        }

        Color& getFillColor() const
        {
            return m_color;
        }

    	void glReleaseTransform() const
        {
            glLoadIdentity();

            glTranslatef(this->m_position.x, this->m_position.y, this->m_position.z);
            glTranslatef(this->m_origin.x, this->m_origin.y, this->m_origin.z);

            glScalef(this->m_scale.x, this->m_scale.y, this->m_scale.z);
        	
            glColor4ub(this->m_color.r, this->m_color.g, this->m_color.b, this->m_color.a);

            glRotatef(this->m_rotation.x, 1, 0, 0);
            glRotatef(this->m_rotation.y, 0, 1, 0);
            glRotatef(this->m_rotation.z, 0, 0, 1);
        }

        void glReleaseTransform(const Transform3D& transform) const
        {
            glLoadIdentity();

            glTranslatef(this->m_position.x, this->m_position.y, this->m_position.z);
            glTranslatef(this->m_origin.x, this->m_origin.y, this->m_origin.z);
        	
            glTranslatef(transform.m_position.x, transform.m_position.y, transform.m_position.z);
            glTranslatef(transform.m_origin.x, transform.m_origin.y, transform.m_origin.z);

            glScalef(this->m_scale.x, this->m_scale.y, this->m_scale.z);
            glScalef(transform.m_scale.x, transform.m_scale.y, transform.m_scale.z);
        	
            glColor4ub(this->m_color.r, this->m_color.g, this->m_color.b, this->m_color.a);
            glColor4ub(transform.m_color.r, transform.m_color.g, transform.m_color.b, transform.m_color.a);

            glRotatef(this->m_rotation.x, 1, 0, 0);
            glRotatef(transform.m_rotation.x, 1, 0, 0);
        	
            glRotatef(this->m_rotation.y, 0, 1, 0);
            glRotatef(transform.m_rotation.y, 0, 1, 0);
        	
            glRotatef(this->m_rotation.z, 0, 0, 1);
            glRotatef(transform.m_rotation.z, 0, 0, 1);
        }

        //inline static Transformable3D DEFAULT_TRANSFORMABLE = Transformable3D();

    };
	

///////////////////////////////////////////////////////////////////////////////
	
	class Point
	{
	public:

		Point(const GLfloat x, const GLfloat y, const GLfloat z,
			const GLfloat tex_cord_x, const GLfloat tex_cord_y,
            const GLfloat normal_x, const GLfloat normal_y, const GLfloat normal_z) :
			//const GLubyte r, const GLubyte g, const GLubyte b,
			//const GLubyte a = 255) :
			x(x),
			y(y),
			z(z),
			tex_cord_x(tex_cord_x),
			tex_cord_y(tex_cord_y),
            normal_x(normal_x),
            normal_y(normal_y),
            normal_z(normal_z)
			//r(r),
			//g(g),
			//b(b),
			//a(a)
		{

		}

        Point(const GLfloat x, const GLfloat y, const GLfloat z,
            const GLfloat tex_cord_x, const GLfloat tex_cord_y) :
            //const GLubyte r, const GLubyte g, const GLubyte b,
            //const GLubyte a = 255) :
            x(x),
            y(y),
            z(z),
            tex_cord_x(tex_cord_x),
            tex_cord_y(tex_cord_y),
            normal_x(x),
            normal_y(y),
            normal_z(z)
            //r(r),
            //g(g),
            //b(b),
            //a(a)
        {

        }

		GLfloat x;
		GLfloat y;
		GLfloat z;

		GLfloat tex_cord_x;
		GLfloat tex_cord_y;

        GLfloat normal_x;
        GLfloat normal_y;
        GLfloat normal_z;
		
		//GLubyte r;
		//GLubyte g;
		//GLubyte b;
		//GLubyte a;
	};

    template <typename _Value_type>
    inline Point toPoint(const _Value_type& type, const GLfloat& tex_cord_x, const GLfloat& tex_cord_y)
    {
        return { type.x, type.y, type.z, tex_cord_x, tex_cord_y};
    }
}

///////////////////////////////////////////////////////////////////////////////

inline std::vector<GLfloat> operator <<
(const sf::Point& point_first, const sf::Point& point_second)
{
    std::vector<GLfloat> pointer;
    pointer.push_back(point_first.x);
    pointer.push_back(point_first.y);
    pointer.push_back(point_first.z);
    pointer.push_back(point_first.tex_cord_x);
    pointer.push_back(point_first.tex_cord_y);
    pointer.push_back(point_first.normal_x);
    pointer.push_back(point_first.normal_y);
    pointer.push_back(point_first.normal_z);
    return pointer;
}

///////////////////////////////////////////////////////////////////////////////

inline std::vector<GLfloat>& operator <<
(std::vector<GLfloat>& pointer, const sf::Point& point_second)
{
    pointer.push_back(point_second.x);
    pointer.push_back(point_second.y);
    pointer.push_back(point_second.z);
    pointer.push_back(point_second.tex_cord_x);
    pointer.push_back(point_second.tex_cord_y);
    return pointer;
}

///////////////////////////////////////////////////////////////////////////////

namespace sf
{

    ///////////////////////////////////////////////////////////////////////////////
	
    class Window3D;

    ///////////////////////////////////////////////////////////////////////////////

    namespace priv
    {
    
        class Texture3D : public Texture
        {
        public:
            explicit Texture3D(const Texture& texture = {});

            mutable int this_tex_num;
        };

        class TextureManager3D
        {

        public:

	        static void registerTexture3D(const Texture3D* const texture)
	        {
                texture->this_tex_num = tex_num_;
                tex_num_++;
            }

	        static void bindTexture3D(const Texture3D* const texture)
            {
	            if (this_tex_num_ != texture->this_tex_num)
	            {
                    glEnable(GL_TEXTURE_2D);
                    Texture::bind(texture);
                    this_tex_num_ = texture->this_tex_num;
	            }
            }

            static void unbindTexture3D()
            {
                sf::Texture::bind(NULL);
            }
        
        private:
        	
            inline static int this_tex_num_;
            inline static int tex_num_;

        };

        inline Texture3D::Texture3D(const Texture& texture) :
    		Texture(texture),
    		this_tex_num(0)
        {
            TextureManager3D::registerTexture3D(this);
        }
    	
    }

	///////////////////////////////////////////////////////////////////////////////

    class Textureable3D
    {
    public:
	    explicit Textureable3D(const Texture& texture = {}) :
    		texture_(texture)
        {
	        
        }

    	void setTexture(const Texture& texture)
        {
            texture_ = priv::Texture3D(texture);
	    }

    	const sf::Texture& getTexture() const
	    {
            return texture_;
	    }

    protected:
        priv::Texture3D texture_;
    };
	
    ///////////////////////////////////////////////////////////////////////////////
	
    class Drawable3D
    {

        friend class Window3D;
    	
    public:
	    virtual ~Drawable3D() = default;;

        explicit Drawable3D(const int pointer_end = 0) : drawable_num_(0),
                                                         pointer_end_(pointer_end),
                                                         pointer_begin_(0)
        {
        }
    
    public:
	    void onGettingPointerBegin(const int pointer_int) const
        {
            pointer_begin_ = pointer_int;
        }
    	
	    void onGettingDrawableNum(const int drawable_num) const
	    {
            drawable_num_ = drawable_num;
	    }


        virtual void  draw(const Transform3D& transform) = 0;

        inline void __fastcall drawArrays(const GLenum mode) const
        {
            glDrawArrays(mode, this->pointer_begin_, this->pointer_end_);
        }
    
    protected:
        mutable int drawable_num_;
        int pointer_end_;
        mutable int pointer_begin_;
        std::vector<GLfloat> points_;
        mutable bool not_reg_ = true;
    };


///////////////////////////////////////////////////////////////////////////////
	
    class Eye : public Drawable, public Transformable3D
    {
    public:

        Eye(const Vector2u window_size, 
            const GLdouble fov = 60., 
            const Vector3<GLfloat>& position = {}, 
            const Vector3<GLfloat>& rotation = {}) :
            fov_(fov),
            aspect_(static_cast<GLdouble>(window_size.x) / 
                static_cast<GLdouble>(window_size.y))
        {
            this->m_position = position;
            this->m_rotation = rotation;
        }

        void draw(RenderTarget& target, RenderStates states) const override
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            gluPerspective(fov_, aspect_, 1.0, 50000);

            /*gluLookAt(
                this->m_position.x, this->m_position.y, this->m_position.z,
                0, 0,0,
                0, 1.0, 0);*/
            glRotatef(this->m_rotation.x, 1, 0, 0);
            glRotatef(this->m_rotation.y, 0, 1, 0);
            glRotatef(this->m_rotation.z, 0, 0, 1);
            glTranslatef(-this->m_position.x, 
                -this->m_position.y, -this->m_position.z);
            //glTranslated(-this->m_origin.x, -this->m_origin.y, -this->m_origin.z);
        }

    	void setFOV(const GLdouble fov) const
        {
            fov_ = fov;
        }

    	GLdouble getFOV() const
        {
            return fov_;
        }

        void setAspect(const Vector2u window_size) const
        {
            aspect_ = static_cast<GLdouble>(window_size.x) /
                static_cast<GLdouble>(window_size.y);
        }

        GLdouble getAspect() const
        {
            return aspect_;
        }
    
    protected:
        mutable GLdouble fov_;
        mutable GLdouble aspect_;
    };

///////////////////////////////////////////////////////////////////////////////


	
///////////////////////////////////////////////////////////////////////////////

    class Window3D : public RenderWindow
    {
    private:
        inline static GLint pointer_begin_ = 0;
        inline static GLint pointer_begin_last_ = 0;
        inline static GLint drawable_enumerator_ = 0;
    
    public:

        inline static std::vector<GLfloat> pointer = {};

    	inline static void reloadPointer(Drawable3D* drawable)
        {
            if (drawable->not_reg_)
            {
                drawable->not_reg_ = false;
                glEnableClientState(GL_VERTEX_ARRAY);
                glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                glEnableClientState(GL_NORMAL_ARRAY);

                glVertexPointer(3, GL_FLOAT,
                    5 * sizeof(GLfloat), pointer.data());
                glTexCoordPointer(2, GL_FLOAT,
                    5 * sizeof(GLfloat), pointer.data() + 3);
                glNormalPointer(GL_FLOAT, 5 * sizeof(GLfloat), pointer.data() + 5);

                // Disable normal and color vertex components

                glDisableClientState(GL_COLOR_ARRAY);
            }
        }

    	static void pushPoint(const Point& point)
        {
            pointer << point;
        }

    	template<typename... _Value_type>
        static void pushPoint(const Point& point_first, const _Value_type&... points)
        {
            pointer << point_first;
            pushPoint(points...);
        }

        virtual ~Window3D() = default;

        Window3D(VideoMode mode, const std::string& title, Uint32 style = 7U,
            const ContextSettings& settings = ContextSettings()) :
            RenderWindow(mode, title, style, settings)
        {

        }

        static GLint registerDrawable3D(const GLint points_num)
    	{

            pointer_begin_ += pointer_begin_last_;
            pointer_begin_last_ = points_num;
            drawable_enumerator_++;
			return pointer_begin_;
    	}
    	
        void draw3D(Drawable3D& drawable, const Transform3D& transformable = {})
        {

            drawable.draw(transformable);
        }
    };

    class Triangle3D : public Transformable3D, public Drawable3D, public Textureable3D
    {
    public:
        static void pushPointsBySize(
            const GLfloat x,
            const GLfloat y,
            const GLfloat origin_x = 0,
            const GLfloat origin_y = 0,
            const GLfloat origin_z = 0)
        {
            Window3D::pushPoint({ origin_x, origin_y, origin_z, 0, 0});
            Window3D::pushPoint({ origin_x, y + origin_y, origin_z, 0, 1 });
            Window3D::pushPoint({ x + origin_x, origin_y, origin_z, 1, 0 });
        }
    	
    public:

    	Triangle3D() :
            Transformable3D(), Drawable3D(3)
        {
            pushPointsBySize(1, 1);
            this->pointer_begin_ = Window3D::registerDrawable3D(3);
        }
    	
        Triangle3D(const Point& point0, const Point& point1, const Point& point2) :
            Transformable3D(), Drawable3D(3)
        {
            Window3D::pushPoint(point0, point1, point2);
            this->pointer_begin_ = Window3D::registerDrawable3D(3);
        }

        Triangle3D(const Vector3f& position, const Vector2f& size) :
            Transformable3D(), Drawable3D(3)
        {
            pushPointsBySize(size.x, size.y);
            this->m_position = position;
            this->pointer_begin_ = Window3D::registerDrawable3D(3);
        }

        Triangle3D(const Vector2f& size) :
            Transformable3D(), Drawable3D(3)
        {
            pushPointsBySize(size.x, size.y);
            this->pointer_begin_ = Window3D::registerDrawable3D(3);

        }

        Triangle3D(const GLfloat size_x, const GLfloat size_y) :
            Transformable3D(), Drawable3D(3)
        {
            pushPointsBySize(size_x, size_y);
            this->pointer_begin_ = Window3D::registerDrawable3D(3);
        }
    	
        void draw(const Transform3D& transform) override
        {
            priv::TextureManager3D::bindTexture3D(&this->texture_);
            Window3D::reloadPointer(this);
            this->glReleaseTransform(transform);
            this->drawArrays(GL_TRIANGLES);
        }
    };

    class Quad3D : public Transformable3D, public Drawable3D, public Textureable3D
    {
    public:
		static void pushPointsBySize(
            const GLfloat x,
            const GLfloat y,
            GLfloat originX = 0,
            GLfloat originY = 0, 
            GLfloat originZ = 0)
		{
            Window3D::pushPoint({ originX, originY, originZ, 0, 0 });
            Window3D::pushPoint({ originX, y + originY, originZ, 0, 1 });
            Window3D::pushPoint({ x + originX, y + originY, originZ, 1, 1 });
            Window3D::pushPoint({ x + originX, originY, originZ, 1, 0 });
		}
    
    public:

        Quad3D() :
            Transformable3D(), Drawable3D(4)
        {
            pushPointsBySize(1, 1,1);
            this->pointer_begin_ = Window3D::registerDrawable3D(4);
        }
    	
        Quad3D(const Point& point0, const Point& point1, const Point&point2, const Point& point4) :
            Transformable3D(), Drawable3D(4)
        {
            Window3D::pushPoint(point0, point1, point2, point4);
            this->pointer_begin_ = Window3D::registerDrawable3D(4);
        }

        Quad3D(const Vector3f& origin, const Vector2f& size) :
            Transformable3D(), Drawable3D(4)
        {
            pushPointsBySize(size.x, size.y, origin.x, origin.y, origin.z);

            this->pointer_begin_ = Window3D::registerDrawable3D(4);
        }

        Quad3D(const Vector2f& size) :
            Transformable3D(), Drawable3D(4)
        {
            pushPointsBySize(size.x, size.y);
            this->pointer_begin_ = Window3D::registerDrawable3D(4);
        }

        Quad3D(const GLfloat size_x, const GLfloat size_y) :
            Transformable3D(), Drawable3D(4)
        {
            pushPointsBySize(size_x, size_y);
            this->pointer_begin_ = Window3D::registerDrawable3D(4);
        }

        void draw(const Transform3D& transform) override
        {
            priv::TextureManager3D::bindTexture3D(&this->texture_);
            Window3D::reloadPointer(this);
            this->glReleaseTransform(transform);
            this->drawArrays(GL_QUADS);
        }
    };

    class Cube3D : public Transformable3D, public Drawable3D, public Textureable3D
    {
    public:
        static GLint pushPointsBySize(
            const GLfloat x,
            const GLfloat y, 
            const GLfloat z,
            GLfloat originX = 0,
            GLfloat originY = 0,
            GLfloat originZ = 0)
        {
            Window3D::pushPoint({ originX, originY, originZ, 0, 0 });
            Window3D::pushPoint({ originX, y + originY, originZ, 0, 1 });
            Window3D::pushPoint({ x + originX, y + originY, originZ, 1, 1 });
            Window3D::pushPoint({ x + originX, originY, originZ, 1, 0 });

            Window3D::pushPoint({ originX, originY, originZ, 0, 0 });
            Window3D::pushPoint({ originX, originY, z + originZ, 0, 1 });
            Window3D::pushPoint({ x + originX, originY, z + originZ, 1, 1 });
            Window3D::pushPoint({ x + originX, originY, originZ, 1, 0 });

            Window3D::pushPoint({ originX, originY, originZ, 0, 0 });
            Window3D::pushPoint({ originX, originY, z + originZ, 0, 1 });
            Window3D::pushPoint({ originX, y + originY, z + originZ, 1, 1 });
            Window3D::pushPoint({ originX, y + originY, originZ, 1, 0 });

            Window3D::pushPoint({ x + originX, originY, originZ, 0, 0 });
            Window3D::pushPoint({ x + originX, originY, z + originZ, 0, 1 });
            Window3D::pushPoint({ x + originX, y + originY, z + originZ, 1, 1 });
            Window3D::pushPoint({ x + originX, y + originY, originZ, 1, 0 });

            Window3D::pushPoint({ originX, y + originY, originZ, 0, 0 });
            Window3D::pushPoint({ originX, y + originY, z + originZ, 0, 1 });
            Window3D::pushPoint({ x + originX, y + originY, z + originZ, 1, 1 });
            Window3D::pushPoint({ x + originX, y + originY, originZ, 1, 0 });

            Window3D::pushPoint({ originX, originY, z + originZ, 0, 0 });
            Window3D::pushPoint({ originX, y + originY, z + originZ, 0, 1 });
            Window3D::pushPoint({ x + originX, y + originY, z + originZ, 1, 1 });
            Window3D::pushPoint({ x + originX, originY, z + originZ, 1, 0 });

            return 24;
        }

    public:

        Cube3D() :
    	Transformable3D(), Drawable3D(24)
        {
            pushPointsBySize(1, 1, 1);
            this->pointer_begin_ = Window3D::registerDrawable3D(24);
        }

        Cube3D(const Vector3f& position, const Vector3f& size) :
            Transformable3D(), Drawable3D(24)
        {
            pushPointsBySize(size.x, size.y, size.z);
            this->m_position = position;
            this->pointer_begin_ = Window3D::registerDrawable3D(24);
        }

        Cube3D(const Vector3f& size) :
            Transformable3D(), Drawable3D(24)
        {
            pushPointsBySize(size.x, size.y, size.z);
            this->pointer_begin_ = Window3D::registerDrawable3D(24);
        }

        Cube3D(const GLfloat size_x, const GLfloat size_y, const GLfloat size_z) :
            Transformable3D(), Drawable3D(24)
        {
            pushPointsBySize(size_x, size_y, size_z);
            this->pointer_begin_ = Window3D::registerDrawable3D(24);
        }

        void draw(const Transform3D& transform) override
        {
            priv::TextureManager3D::bindTexture3D(&this->texture_);
            Window3D::reloadPointer(this);
            this->glReleaseTransform(transform);
            this->drawArrays(GL_QUADS);
        }
    };

    class Sphere3D : public Transformable3D, public Drawable, public Textureable3D
    {
    public:

        Sphere3D() : quadratic_(gluNewQuadric())
        {
            gluQuadricTexture(quadratic_, GL_TRUE);
        }

        Sphere3D(const GLdouble radius) :
    		quadratic_(gluNewQuadric()),
    		radius_(radius),
            slices_(10),
            stacks_(10)
        {
            gluQuadricTexture(quadratic_, GL_TRUE);
        }


        Sphere3D(const GLdouble radius, const GLint slices, const GLint stacks) :
            quadratic_(gluNewQuadric()),
    		radius_(radius),
    		slices_(slices),
    		stacks_(stacks)
        {
            gluQuadricTexture(quadratic_, GL_TRUE);
        }
    	
        void draw(RenderTarget&, RenderStates) const override
        {
            priv::TextureManager3D::bindTexture3D(&(this->texture_));
            this->glReleaseTransform();
            gluSphere(quadratic_, radius_, slices_, stacks_);
        }

        void setRadius(const GLdouble radius) const
        {
            radius_ = radius;
        }

        void setSlices(const GLint slices) const
        {
            slices_ = slices;
        }

        void setStacks(const GLint stacks) const
        {
            stacks_ = stacks;
        }

    	GLdouble getRadius() const
        {
            return radius_;
        }

    	GLint getSlices() const
        {
            return slices_;
        }

    	GLint getStack() const
        {
            return stacks_;
        }
    
    private:
        GLUquadric* quadratic_;
        mutable GLdouble radius_;
        mutable GLint slices_;
        mutable GLint stacks_;
    };
	
}
